#include "file.h"

int func(FILE* f_help, int flag_h, int flag_v, int flag_f, int flag_i, int flag_p, 
          FILE* f1, FILE* f2,  FILE* f2_read,  char* s, char* help, char* f1_name, char* f2_name)
{

    f1 = fopen(f1_name, "r");
    f2_read = fopen(f2_name, "r");
    f2 = fopen(f2_name, "w");

    if(flag_h == 1)
    {
        while((fgets(help, 50, f_help) != NULL))
            fprintf(stdout, "%s", help);
        printf("\n");
        fclose(f_help);
    }

    else
    {
        if(flag_f == 1)
        {
            Print(f1, f2, s);
            if(errno == 9)
            {
                remove(f2_name);
                f2 = fopen(f2_name, "w");
            }
        }
        if(flag_v == 1)
            verbose(f1_name, f2_name);

        if(flag_i ==1)
        {
            if(f2_read != NULL)
            {
            char* answer = interactive();
            if(strcmp(answer, "yes") != 0)
                return 0;
            }
        }
        if(flag_p == 1)
        {
            preserve(f1_name, f2_name);
        }
        Print(f1, f2, s);
    }
    return 0;
}

void verbose(char* f1, char* f2)
{
    printf("%s -> %s\n", f1, f2);
}

char* interactive()
{
    char* answer = (char*)calloc(10, sizeof(char));
    printf("Are you sure?\n");
    scanf("%s", answer);
    return answer;
}

void Print(FILE* f_from, FILE* f_to, char* s)
{
    fseek(f_from, 0, SEEK_SET);
    while((fgets(s, 10, f_from) != NULL))
    {
        fprintf(f_to, "%s", s);
    }
}

void preserve(char* f1_name, char* f2_name)
{
    struct stat from;
    struct stat to;
    struct utimbuf Time;

    stat(f1_name, &from);
    stat(f2_name, &to);

    from.st_atime  = Time.actime;
    from.st_mtime  = Time.modtime;

    utime(f2_name, &Time);

    chown(f2_name, from.st_uid, from.st_gid);
    chmod(f2_name, from.st_mode);

}
