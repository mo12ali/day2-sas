#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void recherche_sous_chaine(char str[], char sub_str[]){
    int length = strlen(str);
    int length_sub = strlen(sub_str);
    int trouve = 0;
    int pos = 0;
    for(int i = 0 ; i < length ; i++){
        for(int j = 0; j < length_sub ; j++){
            if(str[i] != sub_str[j])
                break;
            else{
                trouve = 1;
                pos = i;
            }
        }
    }
    if(trouve != 0){
        printf("la sous chaine : %s : se trouve a la position  %d ",sub_str,pos);
    }else{
        printf("la chaine n'existe pas ");
    }
}
int main(){
                //0123456789
    char str[] = "mohammed ali cherraoui";
    char sub[] = "mo";
    recherche_sous_chaine(str,sub);

    return 0;
}