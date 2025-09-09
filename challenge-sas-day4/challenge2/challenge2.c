#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


void vowelDominance(char str[], int size){
    char vowel[] = "aoueyi";
    int max = size / 2;
    int count_vow = 0;
    for(int i = 0 ; i < size ; i++){
        char c = tolower(str[i]);
        for(int j = 0 ; j < strlen(vowel) ; j++){
            if(c == vowel[j]){
                count_vow++;
                break;  
            }
              
        }
    }
    if(count_vow > max){
        printf("vowel cominant");
    }else{
        printf("consonant dominant");
    }
}
int main(){
    char str[] = "education";
        int size = sizeof(str)/sizeof(char);
    vowelDominance(str,size);
    return 0;
}