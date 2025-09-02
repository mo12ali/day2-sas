#include<stdio.h>
#include<stdlib.h>


int main(){

    int n;
    printf("entrer un nombre entier");
    scanf("%d",&n);
    int somme = 0;
    for(int i=0; i<= n;i++){
        somme += i;
    }
    printf(" la somme est %d",somme);
    return 0;
}