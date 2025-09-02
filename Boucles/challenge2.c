#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l;
    printf("entrer le nombre des lignes");
    scanf("%d", &l);

    for (int i = 0; i < l; i++)
    {

        for (int j = 0; j < l - 1 - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < 2 * i + 1; k++)
        {
            printf("*");
        }

        printf("\n");
        
    }
    return 0;
}
