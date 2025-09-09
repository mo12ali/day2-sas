#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void isPalindrome(char str[]){
    int pal = 0;
    int i = 0;
    int j = strlen(str)-1;
    while(i < strlen(str)/2 + 1 && j >= i){
        if(str[i] == str[j]){
             pal = 1;
        }else{
            pal = 0;
            break;
        }
        i++;
        j--;
    }
    if(pal == 1){
        printf("est palindrome");
    }else{
        printf("n'est pas palindrome");
    }
}

int main(){
    char str[] = "hello";
    isPalindrome(str);
    return 0;
}