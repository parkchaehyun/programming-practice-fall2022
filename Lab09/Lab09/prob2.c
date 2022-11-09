#include <stdio.h>

#define SIZE 4

void merge(int*, int*, int*, int);
void printf_merge(int*, int);

int main(void){
    int A[SIZE] = {2, 5, 7, 9};
    int B[SIZE] = {1, 3, 4, 6};
    int C[SIZE*2] = {0};
    
    int i;
    
    for(i=0;i<SIZE;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    
    for(i=0;i<SIZE;i++){
        printf("%d ", B[i]);
    }
    printf("\n");
    
    merge(&A[0], &B[0], &C[0], SIZE);
    
    printf_merge(&C[0], SIZE*2);
    
    return 0;
}

void merge(int* a, int* b, int* c, int n){
    int i,k;
    
    for(i=0;i<n;i++){
        c[i]=a[i];
    }
    
    for(i=n;i<2*n;i++){
        c[i]=b[i-n];
    }
    
    for(i=0;i<2*n;i++){
        int temp;
        for(k=i+1;k<2*n;k++){
            if(c[i] > c[k]){
                temp = c[i];
                c[i] = c[k];
                c[k] = temp;
            }
        }
    }
    
}

void printf_merge(int* c, int n){
    int i;
    
    for(i=0;i<n;i++){
        printf("%d ", c[i]);
    }
    
    printf("\n");
}
