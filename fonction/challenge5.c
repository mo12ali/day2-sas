#include<stdio.h>
#include<stdlib.h>


int factorielle(int n){
    int fact = 1;
    for(int i = 1; i<= n ;i++){
        fact = fact * i;
    }
    return fact;
}
int main(){
    int n; 
    printf("entrer un nombre a scanner ; ");
    scanf("%d",&n);
    printf(" le factorielle de %d est %d ", n ,factorielle(n));

}