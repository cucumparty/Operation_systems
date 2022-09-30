#include <stdio.h>
#include <stdlib.h>

unsigned int count_nod(unsigned int a, unsigned int b)
{
    while(a != 0 && b != 0)
    {
        if(a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a + b);
}

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int my_nod = 0;

    scanf("%u %u", &a, &b);
    my_nod = count_nod(a, b);
    printf("NOD:%u\n",my_nod);
    return 0;
}