#include<stdio.h>
#include<stdlib.h>


void rechercher_minimum(int tab[], int size){
    int min = 0;
    int ind_min = 0;
    for(int i = 0 ; i < size ; i++){
        if(tab[ind_min] > tab[i]){
            ind_min = i;
        }
    }
    printf("l'element minimum est %d dans l'indice %d ",tab[ind_min],ind_min+1);
}
int main(){
         //      0 1 2 3 4 5 6 7 8  9
        //       | | | | | | | | | /
    int tab[] = {5,6,7,1,3,8,9,12};
   int taille = sizeof(tab)/sizeof(int);
    //int taille = calculer_size_tab_int(tab);
    printf("%d \n",taille);
    rechercher_minimum(tab, taille);


    return 0;
}