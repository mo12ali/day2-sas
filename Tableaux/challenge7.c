#include<stdio.h>
#include<stdlib.h>

void echange(int a, int b){
    int tmp = a; 
    a = b;
    b = tmp;
}


int main(){
    int *tab , taille, i,j;
    printf("%d",&taille);
    tab = (int *)malloc(taille * sizeof(int));
    for(i = 0; i< taille; i++){
        printf("entrez la valeur de la case %d", i+1);
        scanf("%d", (tab + i));
    }
    for(j = 0; j< taille; j++){
        if(tab[j] < tab[j+1]){
            echange(tab[j],tab[j+1]);
        }
    }
    printf("[ ");
    for(int k = 0; k < taille; k++){
        printf("%d ,",tab[k]);
    } 

    printf(" ]");
}