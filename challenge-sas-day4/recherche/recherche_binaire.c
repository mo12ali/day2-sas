#include <stdio.h>
#include <stdlib.h>

/*
 *
 * la critere de la recherche binaire c'est que le tableau doit etre deja trie
 *
 */
// 0 1 2 3 4 5 6 7 8
void recherche_binaire(int tab[], int size, int element)
{
    int mid = size / 2 + 1;
    int i, j;
    if (element < tab[mid])
    {
        for (i = 0; i < mid; i++)
        {
            if (tab[i] == element)
                printf("l'element se trouve dans l'indice : %d ", i);
        }
    }
    else
    {
        for (i = mid; i < size; i++)
        {
            if (tab[i] == element)
                printf("l'element se trouve dans l'indice : %d ", i);
        }
    }
}
int main()
{
    //           0 1 2 3 4 5 6 7 8
    int tab[] = {1,2,3,4,5,6,7,8,9};
    int taille = sizeof(tab) / sizeof(int);

    recherche_binaire(tab, taille, 3);

    return 0;
}