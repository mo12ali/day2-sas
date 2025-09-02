#include<stdio.h>
#include<stdlib.h>


int main(){


    int *tab;
    int taille;
    int i,j,k;
    int facteur;

    
    printf("entrez le nombre des elements du tableau\n");
    scanf("%d",&taille);
    tab = (int *)malloc(taille*sizeof(int));
    
    printf("entrez le facteur : ");
    scanf("%d",&facteur);

    printf("\n");
    for(i = 0;i<taille;i++){
        printf("entrez la case %d : ",i+1);
        scanf("%d",(tab+i));
        tab[i] *= facteur;
        printf("\n");
    }

    
    
    printf("l'affichage du tableau est : ");
    printf("[ ");
    for(k = 0;k<taille; k++){
        printf("%d, ",tab[k]);
    }
    printf(" ]");

    

}