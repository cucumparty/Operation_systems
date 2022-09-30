#include <stdio.h>
#include <stdlib.h>

double diff_of_trunks(unsigned int* trunk, unsigned int N)
{
    int i = 0;
    unsigned int sum = 0;
    for(i = 0; i < N; i++)
    {
        sum += trunk[i];
    }
    return (sum / N);
}

int main()
{
    unsigned int N = 0;
    int i = 0;
    double diff = NULL;

    scanf("%u", &N);

    unsigned int trunk[N];

    for( i = 0; i < N; i++)
        scanf("%u", &trunk[i]);


    diff = diff_of_trunks(trunk, N);

    for(i = 0; i < N; i++)
        printf("%lf\n", diff - trunk[i]);

    return 0;
}