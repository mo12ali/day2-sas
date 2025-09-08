#include<stdio.h>
#include<stdlib.h>


/**
 * 
 *  0 1 2 3 4 5
 *  4 3 7 1 5 2
 *   j < n - i -1 =>    in each iteration the max number is sent to the end of the array or before the last max number
 *                      so to not make the code more complicated and try to not brute force it 
 *                      i is used to calculate the itteration
 * 
 */

void tri_bulle(int tab[], int n){
    for(int i = 0; i< n ; i++){
        for(int j = 0; j < n - i - 1 ; j++){
            if(tab[j] > tab[j+1]){
                int tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }   
        }
    }
}

void print_tab(int tab[] , int n){
    for(int i = 0 ; i < n; i++){
        printf("%d , ",tab[i]);
    }
    printf("\n");
}
int main(){
    int tab[] = {5,9,4,3,7,3};
    int size = sizeof(tab)/sizeof(int);
    //printf("%d %d  %d \n",size,sizeof(int), sizeof(tab));
    print_tab(tab, size);
    tri_bulle(tab, size);
    print_tab(tab, size); 
    return 0;
}