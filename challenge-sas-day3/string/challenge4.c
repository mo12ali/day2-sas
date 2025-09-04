#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100


int main(){
    int check = 0;
    int len1, len2;
    char str1[MAX] , str2[MAX];
    printf("entrer la chaine 1 : \n");
    fgets(str1,sizeof(str1),stdin);
    printf("entrer la chaine 2 : \n");
    fgets(str2,sizeof(str2),stdin);
    len1 = strlen(str1);
    len2 = strlen(str2);
    if(len1 > len2 || len1 < len2){
       // printf("les chaines ne sont pas egaux");
        check = 1;
    }else{
        for(int i = 0; i< len1; i++){
            if(str1[i] != str2[i])
                check = 1;
        }
    }
    if(check == 1){
        printf("les chaines ne sont pas egaux");
    }else{
        printf("les chaines sont egaux");
    }

    return 0;
}