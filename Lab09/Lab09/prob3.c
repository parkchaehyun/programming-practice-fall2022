#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_base_pay(int *arr, int size);
void get_extra_pay(int *arr, int size);
void array_add(int *A, int *B, int *C, int size);
void array_print(int *arr, int size);
int array_sum(int *arr, int size);
int search(int *arr, int size, int search_value);

int main(void){
    srand(time(0));
    int A[10] = {0};
    int B[10] = {0};
    int C[10] = {0};
    int search_value;
    int search_index;
    
    get_base_pay(&A[0], 10);
    get_extra_pay(&B[0], 10);
    
    printf("--------직원들의 기본급-------------\n");
    array_print(&A[0], 10);
    
    printf("--------직원들의 보너스-------------\n");
    array_print(&B[0], 10);
    
    array_add(&A[0], &B[0], &C[0], 10);
    
    printf("\n-------직원들의 월급(기본급+보너스)----------\n");
    array_print(&C[0], 10);

    printf("\n직원들의 월급 총합: %d\n", array_sum(&C[0], 10));

    printf("\n찾는 직원의 월급은? ");
    scanf("%d", &search_value);
    
    search_index=search(&C[0], 10, search_value);

    if(search_index==-1){
        printf("찾는 직원이 없습니다.");
    }
    
    else{
        printf("%d번째 직원입니다.\n", search_index);
    }
    
    return 0;
}

void get_base_pay(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        arr[i]=rand()%100;
    }
}

void get_extra_pay(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        arr[i]=rand()%100;
    }
}

void array_print(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void array_add(int *A, int *B, int *C, int size){
    int i;
    
    for(i=0;i<size;i++){
        C[i]=A[i]+B[i];
    }
}

int array_sum(int *arr, int size){
    int sum=0;
    int i;
    
    for(i=0;i<size;i++){
        sum+=arr[i];
    }
    
    return sum;
}

int search(int *arr, int size, int search_value){
    int i;
    
    for(i=0;i<size;i++){
        if(arr[i]==search_value){
            return i+1;
        }
    }
    
    return -1;
}
