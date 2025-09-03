#include<stdio.h>
#include<stdlib.h>

int somme(int a , int b){
    return a+b;
}

int main(){
    int a , b;
    printf("entrez le premier nombre : \n");
    scanf("%d",&a);
    printf("entrez le deuxieme nombre : \n");
    scanf("%d",&b);
    printf("%d",somme(a,b));


    return 0;
}