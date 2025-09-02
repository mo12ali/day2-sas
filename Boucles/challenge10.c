#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){ 
    srand(0);


    char *Maj, *min;
    int lp;
    char *pswd;
    printf("entrer la longueur du mdp : ");
    scanf("%d",&lp);

    pswd = (char *)malloc(lp*sizeof(char));
    Maj = (char *)malloc(26*sizeof(char));
    Maj = "ABCDEFGHIJKLMNOPQRSTUabcdefghijklmnopqrstu0123456789";

   /* min = (char *)malloc(26*sizeof(char));
    min = "abcdefghijklmnopqrstu";*/
    for(int i = 0; i< lp; i++){
        *(pswd+i) = *(Maj + rand()%63);
    }
    printf("%s",pswd);
    return 0;
}