#include "file.h"

void strmode(int mode, char * buf) {
  const char chars[] = "rwxrwxrwx";
  for (size_t i = 0; i < 9; i++) {
    buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
  }
  buf[9] = '\0';
}


void month_change(char month[], int num)
{
    switch(num)
    {
        case 0: strcpy(month, "Jan");
                break;
        case 1: strcpy(month, "Feb");
                break;
        case 2: strcpy(month, "Mar");
                break;
        case 3: strcpy(month, "Apr");
                break;
        case 4: strcpy(month, "May");
                break;
        case 5: strcpy(month, "Jun");
                break;
        case 6: strcpy(month, "Jul");
                break;
        case 7: strcpy(month, "Aug");
                break;
        case 8: strcpy(month, "Sep");
                break;
        case 9: strcpy(month, "Oct");
                break;
        case 10: strcpy(month, "Nov");
                break;
        case 11: strcpy(month, "Dec");
                break;
    }
}

void l_flag(struct stat info, int* total, int* directory)
{
        struct passwd* pwd= getpwuid(info.st_uid);
        struct group* getgr = getgrgid(info.st_gid);
        char ch;

        char buf[10];
        strmode(info.st_mode, buf);
        if(S_ISREG(info.st_mode))
                ch = '-';
        if(S_ISDIR(info.st_mode))
        {
                ch = 'd';
                *directory = 1;
        }

        struct tm *p;
        p = gmtime(&info.st_mtime);
                    
        char month[4] = "";
        month_change(month, p->tm_mon);

        *total += info.st_blocks;

        printf("%c%s  %2.u %s %s  %6.lld %d %s %d:%d ", ch, buf, info.st_nlink, pwd->pw_name, getgr->gr_name, info.st_size,
                p->tm_mday, month, 3 + p->tm_hour, p->tm_min);        
}

int flag_func(DIR* file, int argc, char** argv, int flag_a, int flag_l, int flag_R)
{

                switch(flag_a + flag_l + flag_R)
                {
                case 0: if(argc == 2)
                                file = opendir(".");
                        else
                                file = opendir(argv[optind + 1]);
                        break; 
                case 1: if(argc == 3)
                                file = opendir(".");
                        else
                                file = opendir(argv[optind + 1]);
                        break;
                case 2: if(argc == 4)
                                file = opendir(".");
                        else
                                file = opendir(argv[optind + 1]);
                        break;
                case 3: if(argc == 5)
                                file = opendir(".");
                        else
                                file = opendir(argv[optind + 1]);
                        break;
                }

        if(file == NULL)
            return EXIT_FAILURE;

        read_file(file, flag_a, flag_l, flag_R);

    return 0;
}

void read_file(DIR* file, int flag_a, int flag_l, int flag_R)
{
        struct dirent* dr;
        struct stat info;
        int total = 0;
        int directory = 0;
        char* recursive[100];
        int len = 0;

        while((dr = readdir(file)) != NULL)
        {
        
            if(flag_l == 1)
            {
                if(flag_a == 1)
                {
                        stat((const char*)dr->d_name, &info);
                        l_flag(info, &total, &directory);
                        if(directory == 1 && dr->d_name[0] != '.')
                        {
                                recursive[len] = dr->d_name;
                                len++;
                        }
                        directory = 0;
                }
                else
                {   
                        if(dr->d_name[0] != '.')
                        {
                                stat((const char*)dr->d_name, &info);
                                l_flag(info, &total, &directory);
                                if(directory == 1)
                                {
                                        recursive[len] = dr->d_name;
                                        len++;
                                }
                        directory = 0;
                        }
                }
            }
            if(flag_a == 1)
                printf("%s\n", dr->d_name);
                
            else
            {
                if(dr->d_name[0] != '.')
                    printf("%s\n", dr->d_name);
            }
        }
        if(flag_l == 1)
                printf("total %d\n", total);

        

        if(flag_R == 1)
        {
                int i = 0;
                for(i = 0; i < len; i++)
                {
                        printf("./%s:\n", recursive[i]);
                        read_file((DIR*) recursive[i], flag_a, flag_l, flag_R);
                        printf("\n");
                }
        }
        closedir(file);
}
