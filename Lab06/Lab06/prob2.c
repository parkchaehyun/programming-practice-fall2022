#include <stdio.h>
#include <time.h>

int is_prime(int);
int is_prime_upgrade(int);
int get_integer(void);

int main(void){
    clock_t start, end;
    float res;
    int n, result;
    
    n = get_integer();
    start=clock();
    result=is_prime(n);
    end=clock();
    
    res=(float)(end-start)/CLOCKS_PER_SEC;
    
    if (result == 1)
        printf("%d는 소수입니다.\n", n);
    else
        printf("%d는 소수가 아닙니다.\n", n);
    
    printf("기존 함수 측정 시간: %f\n", res);
    
    start=clock();
    result=is_prime_upgrade(n);
    end=clock();
    
    res=(float)(end-start)/CLOCKS_PER_SEC;
    
    printf("수정 함수 측정 시간: %f\n", res);

    
    return 0;
}

int get_integer(void){
    int n;
    printf("정수를 입력하시오: ");
    scanf("%d", &n);
    return n;
}

int is_prime(int n) {
    int divisors = 0, i;
    for(i=1;i<=n;i++) {
        if(n%i==0)
            divisors++;
    }
    return (divisors == 2);
}

int is_prime_upgrade(int n) {
    int i;
    for(i=2;i<=n-1;i++) {
        if(n%i==0)
            return 0;
    }

    return 1;
}
