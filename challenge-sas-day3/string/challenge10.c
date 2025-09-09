#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void search(char *pat, char *txt){
    int m = strlen(pat); //2
    int n = strlen(txt); //11
    for(int i = 0 ; i <= n - m ; i++ ){
        int j;
        for(j = 0 ; j < m ; j++){
            if(txt[i+j] != pat[j])
                break;
        }
        if(j == m){
            printf("pattern found at the index %d ",j);
        }
    }        
}

int main(){
//                012345678910
    char txt[] = "AABCCAADDEE";
    char pat[] = "DE";
    search(pat,txt);

    return 0;
}