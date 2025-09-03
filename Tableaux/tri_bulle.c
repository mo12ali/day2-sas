#include<stdio.h>
#include<stdlib.h>



void echange(int a , int b){
    int tmp = a;
    a = b;
    b = tmp;
}
void tri_bulle(int t[], int taille){
    for(int i = 0; i < taille ; i++){
        for(int j = 0; j < taille -i -1; j++){
            if(t[j] > t[j+1])
                echange(&t[j],&t[j+1]);
        }
    }
}
int main(){
    return 0;
}