#include <stdio.h>
#include <stdlib.h>

void isMirror(int tab[], int size)
{
    int i = 0;
    int j = size - 1;
    int mirr = 1;
    while (i <= j && j >= i)
    {
        if (tab[i] != tab[j])
        {
            mirr = 0;
            break;
        }
        i++;
        j--;
    }
    if(mirr){
        printf("Mirror array\n");
    }else{
        printf("Not Mirror");
    }
        
    
}
int main()
{

    int tab[] = {3,5,7,9,8,7,5,3};
    int size = sizeof(tab)/sizeof(tab[0]);
    isMirror(tab,size);

    return 0;
}