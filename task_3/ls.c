#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(strcmp("sum", argv[3]) == 0)
        printf("%d\n", atoi(argv[1]) + atoi(argv[2]));

    if(strcmp("sub", argv[3]) == 0)
        printf("%d\n", atoi(argv[1]) - atoi(argv[2]));
    
    if(strcmp("mul", argv[3]) == 0)
        printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

    if(strcmp("div", argv[3]) == 0)
        printf("%d\n", atoi(argv[1]) / atoi(argv[2]));

    return 0;
}