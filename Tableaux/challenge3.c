#include<stdio.h>
#include<stdlib.h>


int main(){


    int taille, *tab;
    int i,j;
    printf("entrez la taille du tableau ");
    scanf("%d",&taille);
    tab = (int *)malloc(taille*sizeof(int));
    

    for(i = 0;i<taille;i++){
        printf("entrez la case %d : ",i+1);
        scanf("%d",(tab+i));
        printf("\n");
    }
    printf("la somme est : ");
    int somme = 0;
    for(j = 0;j<taille; j++){
       somme += tab[j];
    }
    printf("%d",somme);
    return 0;
}