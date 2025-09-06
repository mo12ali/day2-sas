#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
void supprimer_retour_ligne(char *str){
        int len = strlen(str);
        if(len > 0  && str[len -1] =='\n')
            str[len -1] = '\0';

}
int main(){

    
    char buffer[MAX];
    
    printf("entrer le mot a changer en majuscules ");
    fgets(buffer, sizeof(buffer), stdin);
    supprimer_retour_ligne(buffer);
    char maj[strlen(buffer)];
    for(int i = 0; i < strlen(buffer); i++){
        maj[i] = buffer[i]-32;
    }
    printf("%s",maj);
    /**
    for(int i = 0 ; i< 100;i++){
        char test = 'A'+i;
        printf("%c %d \n",test,i);
    }
    */
    return 0;
}