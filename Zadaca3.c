#include <stdio.h>
#include <stdlib.h>

int kolinearni(int A[], int B[]){
    return (A[0] == B[0] && A[1] == B[1] && A[2] == B[2] && A[3] == B[3]) ||
           (A[0] == B[2] && A[1] == B[3] && A[2] == B[0] && A[3] == B[1]);
}

int tocka(int A[], int B[]){
    return (A[0]==B[0] && A[1]==B[1]) || (A[0]==B[2] && A[1]==B[3]) ||
           (A[2]==B[0] && A[3]==B[1]) || (A[2]==B[2] && A[3]==B[3]);
}

int check_for_triangle_by_coords(int A[], int B[], int C[]){
    if(A[0]<-100 || A[0]>100 || A[1]<-100 || A[1]>100 ||
       A[2]<-100 || A[2]>100 || A[3]<-100 || A[3]>100 ||
       B[0]<-100 || B[0]>100 || B[1]<-100 || B[1]>100 ||
       B[2]<-100 || B[2]>100 || B[3]<-100 || B[3]>100 ||
       C[0]<-100 || C[0]>100 || C[1]<-100 || C[1]>100 ||
       C[2]<-100 || C[2]>100 || C[3]<-100 || C[3]>100)
       return -1;

    if(kolinearni(A, B) || kolinearni(A, C) || kolinearni(B, C))
       return 0;

    return (tocka(A, B)+tocka(A, C)+tocka(B, C) == 3); //dali imaat 3 zaednicki tocki.
}

int main(){
    int K[] = {2, 3, 6, 9};
    int L[] = {8, 1, 6, 9};
    int M[] = {8, 1, 2, 3};
    int X[] = {1, 7, 6, 9};

    printf("%d\n", check_for_triangle_by_coords(K, L, M));
    printf("%d\n", check_for_triangle_by_coords(L, K, M));
    printf("%d\n", check_for_triangle_by_coords(M, K, L));
    printf("%d\n", check_for_triangle_by_coords(L, L, M));
    printf("%d\n", check_for_triangle_by_coords(X, L, M));

    return 0;
}
