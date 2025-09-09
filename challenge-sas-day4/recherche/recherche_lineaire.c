#include<stdio.h>
#include<stdlib.h>

void recherche_lineaire(int tab[], int size, int element){
    for(int i = 0 ; i < size ; i++){
        if(tab[i] == element)
            printf("l'element se trouve a la place : %d ",i);
    }
}

int main(){
    //                   |
    //           0 1 2 3 4 5 6 7 8 
    int tab[] = {9,1,7,5,3,2,4,8,6};
    int taille = sizeof(tab)/sizeof(int);
    recherche_lineaire(tab,taille, 3);
    return 0;
}