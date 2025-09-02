#include<stdio.h>
#include<stdlib.h>

void echange(int a, int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void print_table(int *tab, int taille){
    printf("[ ");
    for(int i = 0; i< taille; i++){
        printf("%d , ",*(tab + i));
    }
    printf(" ]");
}
int main(){


    int *tab,taille;
    printf("entrer la taille du tableau : ");
    scanf("%d",&taille);
    tab = (int *)malloc(taille * sizeof(int));
    for(int i = 0; i< taille; i++){
        printf("entrer nombre de la case %d : ",i+1);
        scanf("%d",(tab + i));
    }
    print_table(tab,taille);
    printf("\n");
    
    for(int i =taille -1  ;i >= 1; i--){
        for(int j = 0 ; j< i-1; j++){
            if(tab[j+1] > tab[j]){
                echange(tab[j+1] , tab[j]);
            }
        }
    }
    print_table(tab,taille);

    

    return 0;
}