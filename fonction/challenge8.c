#include<stdio.h>
#include<stdlib.h>


int isPaire(int n){
    if(n % 2 != 0)
        return 0;
    return 1; 
}
int main(){
    int a = 2;
    int b = 5;
    int c = 11;
    int d = 8;
    printf("a est %d \n",isPaire(a));
    printf("b est %d \n",isPaire(b));
    printf("c est %d \n",isPaire(c));
    printf("d est %d \n",isPaire(d));

    return 0;
}