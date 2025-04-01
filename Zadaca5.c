#include <stdio.h>
#include <stdlib.h>

int find_missing_element(int A[], int N){
    int ocekuvana_suma= (N+1)*(N+2) / 2;
    int suma= 0;

    for(int i=0; i<N; i++){
        suma= suma + A[i];
    }
    if(ocekuvana_suma-suma == N+1)
    return 0;
    return ocekuvana_suma-suma ;
}

int main(){
    int A[]= {2,3,1,5};
    int N= sizeof(A) / sizeof(A[0]);

    int rez= find_missing_element(A, N);

     if(rez==0)
          printf("Не недостасува број.\n");
     else printf("%d\n", rez);

    //ova raboti samo ako nizata zapocnuva od 1!
    //ako ne zapocnuva bi bile potrebni max i min ili da se sortira pa proveruva(no slozenosta na toa resenie bi bila O(N²)).

    return 0;
}
