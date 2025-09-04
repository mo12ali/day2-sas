#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
int main(){

    char str[MAX];
    printf("entrer une chaine a inverser");
    fgets(str,sizeof(str),stdin);
    char inverse[strlen(str)];
    for(int i = strlen(str) -1,j = 0 ; i>=0 , j < strlen(inverse);i-- , j++ ){
        inverse[j] = str[i];
    }
    printf("%s",inverse);
    return 0;
}