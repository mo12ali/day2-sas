#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void tir_par_selection(int *tab, int n){
    int min;
    for(int i = 0 ; i < n - 1 ; i++){
        min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(tab[j]  < tab[min])
                swap(&tab[j], &tab[min]);
        }
        
    }
}

void print_tab(int *tab , int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d ,",tab[i]);
    }
    printf("\n");
}
int main(){

    int tab[] = {0,9,4,3,7,56,9};
    int taille = sizeof(tab)/sizeof(int);
    print_tab(tab,taille);
    tir_par_selection(tab,taille);
    print_tab(tab,taille);

    return 0;
}