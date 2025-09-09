#include <stdio.h>

int isUnique(int *tab, int size){
    int unique = 0;
    for(int i = 0; i < size; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if(tab[i] == tab[j]){
                count++;
            }
        }
        if(count == 1){ // only one occurrence means unique
            unique++;
        }
    }
    return unique;
}

int main(){
    int arr[] = {1,2,2,3,4,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", isUnique(arr, size)); // Should print 3: unique numbers are 1,3,5

    return 0;
}
