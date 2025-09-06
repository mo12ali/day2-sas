#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
/**
 * 
 * 
 *  Challenge 6 : Compte des Occurrences d'un Caractère
    Écrivez un programme C qui lit une chaîne de caractères et un caractère,
    puis compte et affiche combien de fois le caractère apparaît dans la chaîne.
 */

 int main(){
    int occ = 0;
    char c;
    char str[MAX];
    printf("entrer une chaine : \n");
    fgets(str, sizeof(str), stdin);
    printf("entrer caractere a chercher : \n");
    scanf("%c",&c);

    for(int i =0 ;i<strlen(str); i++){

        if(str[i] == c)
            occ ++;

    }
    printf("nombre d'occurence du caractere %c dans la chaine %s est %d ",c,str,occ);
 }