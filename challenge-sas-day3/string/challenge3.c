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
    char str1[MAX], str2[MAX];
    
    
    printf("entrez la chaine 1 : \n");
    fgets(str1, sizeof(str1),stdin);
    printf("entrez la chaine 2 : \n");
    fgets(str2, sizeof(str2),stdin);
    int lenTotal = strlen(str1) + strlen(str2);
    char res[lenTotal];
   /* for(int i = 0 ; i < strlen(str1) ; i++){
         res[i] = str1[i];
    }    
    supprimer_retour_ligne(res);
    for(int i = strlen(str1) ; i < lenTotal ; i++){
        res[i] = str2[i];
    }
    */
    strcpy(res, str1);
    supprimer_retour_ligne(res);
    strcat(res,str2);
    printf("la premiere chaine est %s et la deuxieme est %s et la resultante est %s",str1, str2, res);
}