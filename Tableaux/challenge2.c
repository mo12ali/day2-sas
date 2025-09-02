#include<stdio.h>
#include<stdlib.h>


int main(){


    int taille, *tab;
    printf("entrez la taille du tableau ");
    scanf("%d",&taille);
    tab = (int *)malloc(taille*sizeof(int));
    

    for(int i = 0;i<taille;i++){
        printf("entrez la case %d : ",i+1);
        scanf("%d",(tab+i));
        printf("\n");
    }
    printf("[ ");
    for(int i = 0;i<taille; i++){
        printf("%d, ",tab[i]);
    }
    printf(" ]");
    return 0;
}