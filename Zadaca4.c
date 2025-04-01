#include<stdio.h>
#include<stdlib.h>

int* rank_properties(int prices[], int N){
    static int rezultat[100];
    int atraktivnost[N];

    for(int i=0; i<N; i++){
        atraktivnost[i]= (prices[(i-1+N) % N]+prices[i]+prices[(i+1) % N]) / 3;
        rezultat[i]= i;
    }

    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            if(atraktivnost[rezultat[j]] < atraktivnost[rezultat[j+1]]){
                int temp= rezultat[j];
                rezultat[j]= rezultat[j + 1];
                rezultat[j+1]= temp;
            }
        }
    }//bubble sort.
    return rezultat;
}

int main(){
    int prices[]= {6, 10, 14, 11, 18, 9, 12, 7};
    int N= sizeof(prices) / sizeof(prices[0]);

    int *rez= rank_properties(prices, N);

    printf("[");
    for(int i = 0; i < N; i++){
       if(i==N-1)
            printf("%d]", rez[i]);
       else printf("%d,", rez[i]);
    }
    return 0;
}
