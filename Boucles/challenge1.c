#include<stdio.h>
#include<stdlib.h>


int main(){
    int nb;
    printf("entrer un nomre");
    scanf("%d",&nb);
    while(nb>0){
        printf("%d \n",nb*5);
        nb --;
    }
    return 0;
}