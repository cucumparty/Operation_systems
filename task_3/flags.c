#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char** argv)
{
    const struct option long_option[] =
    {
        {"add", no_argument, NULL, 'a'},
        {"sub", no_argument, NULL, 's'}, 
        {"mul", no_argument, NULL, 'm'},
        {"div", no_argument, NULL, 'd'},
        {NULL, no_argument, NULL, 0}
    };

    int flag_a = 0;
    int flag_s = 0;
    int flag_m = 0;
    int flag_d = 0;

    int ret = 0;

    int long_index;
    int opt;
    const char short_option[] = "asmd";

    while((opt = getopt_long(argc, argv, short_option, long_option, &long_index)) != -1)
    {
        switch(opt)
        {
            case 'a': flag_a = 1;
                break;
            case 's': flag_s = 1;
                break;
            case 'm': flag_m = 1;
                break;
            case 'd': flag_d = 1;
                break;
            case '?': printf("Unknown parameter: -%c\n", optopt);
        }
    }
    if(flag_a == 1)
        ret = atoi(argv[optind]) + atoi(argv[optind + 1]);

    if(flag_s == 1)
    {
        if(ret == 0)
            ret = atoi(argv[optind]) - atoi(argv[optind + 1]);
        if(ret != 0)
            ret -= atoi(argv[optind + 1]);
    }

    if(flag_m == 1)
    {
        if(ret == 0)
            ret = atoi(argv[optind]) * atoi(argv[optind + 1]);
        if(ret != 0)
            ret *=  atoi(argv[optind + 1]);
    }

    if(flag_d == 1)
    {
        if(ret == 0)
            ret = atoi(argv[optind]) / atoi(argv[optind + 1]);
        if(ret != 0)
            ret =ret / atoi(argv[optind + 1]);
    }

    printf("Result is %d", ret);
    return 0;
}