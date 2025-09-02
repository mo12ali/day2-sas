#include<stdio.h>
#include<stdlib.h>
void print_table(int *tab, int taille){
    printf("[ ");
    for(int i = 0; i< taille; i++){
        printf("%d , ",*(tab + i));
    }
    printf(" ]");
}

int main(){

    int somme = 0;
    int i,j;
    int nb;
    int tab[10];
    printf("entrer le nombre a miltiplier");
    scanf("%d",&nb);
    for(i = 0 ; i < 10 ; i++){
        tab[i] = (i+1) * nb;
        somme += tab[i];
    }
    print_table(tab,10);
    printf("\n");
    printf("la somme est %d ",somme);
    return 0;
}       