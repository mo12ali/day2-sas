#include<stdio.h>
#include<stdlib.h>


void tri_par_insertion(int *tab, int n){
        int key = 0;
        int j;
        for(int i = 1; i < n ; i++){
            key = tab[i];
            //while here manage the swapping in case there is an unsorted pattern
            j = i - 1;
            while( j >= 0 && key < tab[j]){
                tab[j+1] = tab[j];
                j--;
            }
            //manage the swap if the first 2 cases are unsorted , the rest of the swap is managed within the for loop
            tab[j + 1] = key;
        }
}

void print_tab(int tab[] , int n){
    for(int i = 0 ; i < n; i++){
        printf("%d , ",tab[i]);
    }
    printf("\n");
}


int main(){

    int tab[] = {5,9,4,3,7,3};
    int size = sizeof(tab)/sizeof(int);
    //printf("%d %d  %d \n",size,sizeof(int), sizeof(tab));
    print_tab(tab, size);
    tri_par_insertion(tab, size);
    print_tab(tab, size); 
    return 0;
    return 0;
}