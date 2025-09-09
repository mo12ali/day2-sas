#include<stdio.h>
#include<stdlib.h>
/**
 * 🔹 Challenge 3 (Hard) – Consecutive Block Finder
Problem:
 You are given an array of integers (size ≤ 30). Write a program to find the longest block of consecutive identical numbers and print both the number and its length.
Example:
Input: [1, 1, 2, 2, 2, 3, 3, 2]
 Output: Number: 2, Length: 3

Input: [5, 5, 5, 5, 1, 1, 2, 2]
 Output: Number: 5, Length: 4
 */

void consecutive(int *tab){
    int max = 0, num = 0, cpt = 0;
    int taille = sizeof(tab)/sizeof(int);
    for(int i = 0 ; i < taille ; i++){
        for(int j = i+1; j < taille -1 ; j++){
            /*if(tab[i] == tab[j]){
                cpt ++;
                printf("%d \n",cpt);
            }else*/ if(tab[i] != tab[j]){
                cpt ++;
                max = max > cpt ? max : cpt;
                printf("%d \n",max);
                if(max == cpt){
                    num = tab[i];
                printf("%d \n",tab);
                }
                cpt = 0;
            }
        }
    }
    printf("NUmber : %d , length : %d",num, max);
}
int main(){
    int tab[] = {5,5,5,5,1,1,2,2};
    consecutive(tab);

    return 0;
}