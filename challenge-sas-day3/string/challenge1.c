#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int main(){

    /*
    affichage d'une chaine de caractère*/
    char str[MAX];
    printf("entrer une chaine : \n");
    fgets(str, sizeof(str), stdin);
    printf("%s ",str);
    return 0;
}