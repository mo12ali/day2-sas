#include<stdio.h>
#include<stdlib.h>


int main(){


    int *tab;
    int taille;
    int i,j,k;
    int max = 0;
    printf("entrez le nombre des elements du tableau\n");
    scanf("%d",&taille);
    tab = (int *)malloc(taille*sizeof(int));
    

    for(i = 0;i<taille;i++){
        printf("entrez la case %d : ",i+1);
        scanf("%d",(tab+i));
        printf("\n");
    }
    
    printf("l'affichage du tableau est : ");
    printf("[ ");
    for(k = 0;k<taille; k++){
        printf("%d, ",tab[k]);
    }
    printf(" ]");

    max = tab[0];
    for(j = 1;j<taille;j++){
        if(max < tab[j])
            max = tab[j];
    }

    printf("\nle nombre max est %d ",max);

}