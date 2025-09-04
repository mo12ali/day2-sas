#include<stdio.h>
#include<stdlib.h>

#define MAX 100
    /**
     * longueur d'une chaine sans utiliser strlen
     */

int main(){ 
    char str[MAX];
    int len = 0;

    printf("entrer une chaine : \n");
    fgets(str, sizeof(str),stdin);
    while(str[len]){
        len++;

    }
    printf(" la longeur de %s est %d ",str,len - 1);
    return 0;
}