#include <stdio.h>
#include <stdlib.h>

void paint(int x, int y, char coordinates[][10], char color)
{
    coordinates[x][y] = color;
}
 
char query(int x, int y, char coordinates[][10])
{
    if (coordinates[x][y] == 'B')
        return 'B';
    if (coordinates[x][y] == 'R')
        return 'R';
    return 0;
}

int main()
{
    char coordinates[10][10];

    unsigned int n = 0;
    scanf("%u", &n);

    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j ++)
        {
            coordinates[i][j] = 'N';
        }
    }

    int ident = 0;
    int x = 0;
    int y = 0;
    char color;
    int counter = 0;
    char dot_color[100];

    for(i = 0; i < n; i++)
    {
        scanf("%d",&ident);
        if(ident == 1)
        {
            scanf("%d %d %c", &x, &y, &color);
            paint(x, y, coordinates, color);
        }
        if(ident == 2)
        {
            scanf("%d %d", &x, &y);
            dot_color[counter] = query(x, y, coordinates);
            counter++;
        }
        fflush(stdin);
    }

    for(i = 0; i < counter; i++)
        printf("%c\n", dot_color[i]);

    return 0;
}