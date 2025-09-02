#include<stdio.h>
#include<stdlib.h>


int main(){


    //12345 => 54321
    /**
     * 
     * 12345%10 = 5
     * rn ()
     * 
     * 
     */
    int nb ;
    printf("entrer un nombre a inverser : ");
    scanf("%d",&nb);
    int nombre_inverse = 0;
    int reste = 0;
    while(nb){
        reste = nb % 10;
        nombre_inverse = (nombre_inverse * 10 + reste);
        nb /= 10;
    }
    printf("le nombre apres l'inversion : ");
    printf("%d",nombre_inverse);
    return 0;
}