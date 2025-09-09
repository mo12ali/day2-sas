#include<stdio.h>
#include<stdlib.h>

/**
 * Écrivez un programme C qui implémente l'algorithme de tri rapide pour trier un tableau d'entiers.
 * Affichez le tableau avant et après le tri.
 */


void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void print_tab(int *tab , int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d ,",tab[i]);
    }
    printf("\n");
}


/*
void tri_rapide(int tab[], int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = size-1  ; j >= 0 ; j--){
            if(tab[i] > tab[j]){
                swap(&tab[i], &tab[j]);
            }
        }
    }
}

*/

int partition(int tab[], int low , int high){
    int pivot = tab[high];
    int i = (low - 1);
    
}
void tri_rapide(int tab[], int size){
    int left = 0;
    int right = size -1;
    /*int pivot_index = left + rand() % (right - left + 1);
    int pivot = tab[pivot_index];*/



}

int main(){
    int tab[] = {1,3,4,8,0,5,6,8,11};
    int size = sizeof(tab)/sizeof(int);
    print_tab(tab,size);
    tri_rapide(tab, size);
    print_tab(tab,size);
    
    
    return 0;
}