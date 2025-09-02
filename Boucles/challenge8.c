#include<stdio.h>
#include<stdlib.h>


/**
 * 
 *  0 1 2 3 4 5 6
 * [1,2,3,4,5,6,7] taille = 7
 * miliieu = 7/2 = 3
 */
int main(){
    int *tab, taille = 7;
    tab = (int *)malloc(taille*sizeof(int));
    for(int i = 0; i<taille ; i++){
        tab[i] = i+1;
    }
    int target = 20;
    //int i;
    if(target > tab[taille/2]){

        for(int i = taille/2 ; i < taille ; i++){
            if(tab[i] == target)
                printf("trouve b1");
        }

    }else if(target < tab[taille/2]){

        for(int i = 0; i<taille/2 ; i++){
            if(tab[i] == target)
                printf("trouve b2");
        }
  
    }else{
        printf("n'est pas trouve");
    }
    return 0;
}