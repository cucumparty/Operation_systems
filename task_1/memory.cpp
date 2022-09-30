#include <stdio.h>
#include <stdlib.h>

void evenness(int* array)
{
    if(*array % 2 == 0)
        *array *= 2;
    else   
        *array += 2;
}

int main()
{
    unsigned int N = 0;
    scanf("%u", &N);

    int* array = (int*) calloc(N, sizeof(int));
    int i = 0;

    for(i =0; i < N; i++)
    {
        scanf("%d", &array[i]);
        evenness(&array[i]);
    }
    for(i = 0; i < N; i++)
        printf("%d\n", array[i]);
    free(array);
}