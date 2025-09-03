    #include<stdio.h>
    #include<stdlib.h>



    /**
     * 
     * 
     * 
     *  0+1 = 1
     *   /  /
     *  1+1 = 2
     *   /  /
     *  1+2 = 3
     *   /  /
     *  2+3 = 5
     *   /  /
     *  3+5 = 8
     */
    void print_tab(int *tab, int n){
        for(int i =0; i< n ; i++){
            printf("%d ",tab[i]);
        }
    }
    void fiboncci(int *tab, int n){
        int i;
        tab[0] = 0;
        tab[1] = 1;
        for(i = 2; i< n; i++){
            tab[i] = tab[i - 1]+tab[i - 2];
        }
    }
    int main(){
        int *tab;
        int n ;
        printf("entrer le n-eme terme");
        scanf("%d",&n);
        tab = (int *)malloc((n+1) * sizeof(int));
        fiboncci(tab, n);
        print_tab(tab, n);


    }