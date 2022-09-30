#include "file.h"

int main(int argc, char** argv)
{
    const struct option long_option[] =
    {
        {"all", no_argument, NULL, 'a'},
        {"long", no_argument, NULL, 'l'}, 
        {"recursive", no_argument, NULL, 'R'},
        {NULL, no_argument, NULL, 0}
    };
	int long_index = 0;
    int opt = 0;
    const char short_option[] = "alR";
    
    int flag_a = 0, flag_l = 0, flag_R = 0;
    
    
    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
        case 'a': flag_a = 1;
            break;
        case 'l': flag_l = 1;
            break;
        case 'R': flag_R = 1;
            break;
        case '?': printf("Unknown parameter: -%c\n", optopt);
        }
    }

    DIR* file = NULL;
    flag_func(file, argc, argv, flag_a, flag_l, flag_R);

    
    return 0;
}