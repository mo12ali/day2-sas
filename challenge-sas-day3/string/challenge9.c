#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
/**
 * suppression des espaces
 */
int main(){
   
    char myStr[MAX];
    int c_space = 0;
    printf("entrer une chaine avec des espaces : \n");
    fgets(myStr,sizeof(myStr),stdin);
    int j = 0 ;
    int len = strlen(myStr);
    int len_res = 0;
    for(int i = 0 ; i< len;i++){
        if(myStr[i] == ' ')
            c_space ++;
    }
    char res[len - c_space];
    for(int i = 0 ; i < len ; i++){
        if(myStr[i] != ' ')
            res[j++ ] = myStr[i];
    }
    printf("%s",res);
    return 0;
}