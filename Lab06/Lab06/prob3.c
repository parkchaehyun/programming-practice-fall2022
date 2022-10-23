#include <stdio.h>

int call_program(void);
void letter_case(void);
void even_odd(void);
void factorial(void);


int main(void){
    int n=1;
    
    while(n!=0){
        n=call_program();
    }
    
    return 0;
}

int call_program(void){
    int n;
    
    printf("1. 대소문자 확인\n");
    printf("2. 홀수 짝수 확인\n");
    printf("3. N 팩토리얼 구하기(N!)\n");
    printf("0. 종료\n");
    
    
    scanf("%d", &n);
    getchar();
    
    switch(n) {
        case 0 :
            return 0;
        case 1 :
            letter_case();
            break;
        case 2 :
            even_odd();
            break;
        case 3 :
            factorial();
            break;
        default:
            printf("올바른 입력이 아닙니다.\n");
    }
    
    return 1;
}

void letter_case() {
    char c;
    printf("영문자를 입력하세요: ");
    scanf("%c", &c);
    
    if(c>='A' && c<='Z') {
        printf("'%c'는 대문자입니다.\n", c);
    }
    
    else if(c>='a' && c<='z') {
        printf("'%c'는 소문자입니다.\n", c);
    }
    
    else {
        printf("'%c'는 영문자가 아닙니다.\n", c);
    }
}

void even_odd() {
    int n;
    printf("정수를 입력하세요: ");
    scanf("%d", &n);
    
    if(n%2==0){
        printf("%d는(은) 짝수입니다.\n", n);
    }
    
    else {
        printf("%d는(은) 홀수입니다.\n", n);
    }
}

void factorial() {
    int n, result=1;
    printf("정수를 입력하세요: ");
    scanf("%d", &n);
    
    if(n<0){
        printf("음이 아닌 정수를 입력하세요\n");
        return;
    }
    
    if(n!=0){
        for(int i=n;i>1;i--){
            result=result*i;
        }
    }
    
    printf("%d!은 %d입니다.\n", n, result);
}
