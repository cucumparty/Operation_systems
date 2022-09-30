#include "file.h"

int main(int argc, char** argv)
{
    FILE* f1;
    FILE* f2_read;
    FILE* f2;

    FILE* f_help = fopen("help.txt", "r"); 

    char* s = (char*)calloc(10, sizeof(char));
    char* help = (char*)calloc(50, sizeof(char));

    const struct option long_option[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"verb", no_argument, NULL, 'v'},  
        {"fors", no_argument, NULL, 'f'},
        {"inte", no_argument, NULL, 'i'},
        {"pres", no_argument, NULL, 'p'},
        {NULL, no_argument, NULL, 0}
    };
	int long_index = 0;
    int opt = 0;
    const char short_option[] = "hvfip";
    
    int flag_h = 0, flag_v = 0, flag_f = 0, flag_i = 0, flag_p = 0;
    
    
    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
        case 'h': flag_h = 1;
            break;
        case 'v': flag_v = 1;
            break;
        case 'f': flag_f = 1;
            break;
        case 'i': flag_i = 1;
            break;
        case 'p': flag_p = 1;
            break;            
        case '?': printf("Unknown parameter: -%c\n", optopt);
        }
    }

    func(f_help, flag_h, flag_v, flag_f, flag_i, flag_p, 
          f1, f2, f2_read,  s, help, argv[optind + 1], argv[optind + 2]);
    
    fclose(f1);
    fclose(f2);
    return 0;
}