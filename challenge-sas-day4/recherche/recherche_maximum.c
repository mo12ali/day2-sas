#include<stdio.h>
#include<stdlib.h>


void rechercher_max(int tab[], int size){
    int max = 0;
    int ind_max = 0;
    for(int i = 1 ; i < size ; i++){
        if(tab[ind_max] < tab[i]){
           ind_max = i;
        }
    }
    printf("le nombre max est %d et se trouve a la position : %d \n",tab[ind_max],ind_max+1);
}
/*int calculer_size_tab_int(int *tab){
    return (int) sizeof(tab)/sizeof(int);
}*/

int main(){
        //       0 1 2 3 4 5 6 7 8  9
        //       | | | | | | | | | /
    int tab[] = {1,5,6,7,1,3,8,9,12};
   int taille = sizeof(tab)/sizeof(int);
    //int taille = calculer_size_tab_int(tab);
    printf("%d \n",taille);
    rechercher_max(tab, taille);

    return 0;
}