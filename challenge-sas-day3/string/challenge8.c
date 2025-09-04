#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
int main(){
    char buffer[MAX];
    
    printf("entrer le mot a changer en miniscule ");
    fgets(buffer, sizeof(buffer), stdin);
    char min[strlen(buffer)];
    for(int i = 0; i < strlen(buffer); i++){
        min[i] = buffer[i]+32;
    }
    printf("%s",min);
    
    return 0;
}