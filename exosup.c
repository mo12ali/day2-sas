#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
   int nb; 
   double prix;
}produits;
int main(){
   produits stock[3] = {
        {1, 125.00},
        {2, 2.0},
        {3, 2.5}
    };
    int n;
    double total = 0.00 , prct = 0.00;
    int id;

    printf("id et nombre de produit : ");

    scanf("%d %d",&id,&n);

   
//test

    for(int i = 0; i<sizeof(stock)/sizeof(produits); i++){
        if(stock[i].nb == id){
            for(int j = 1 ; j <= n ; j++){
                total += (stock[i].prix - stock[i].prix * prct);
                prct += 0.02;
            }
        }
    }
    /**
     * 
     * 
     * t1 = 125 + (125 - 125*0%)
     * t2 = t1 + (125 - 125*2%)
     */

    printf("le prix a payer est : %.2f",total);


    return 0;
}
