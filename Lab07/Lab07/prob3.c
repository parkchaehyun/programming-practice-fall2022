#include <stdio.h>

int find_triangular(int);
void show_digit(int);

int main(void) {
    int op, num;

    while(1) {
        printf("1. 삼각수 구하기\n");
        printf("2. 정수의 각 자릿수 출력하기\n");
        printf("3. 종료\n");
        printf("--------------------\n");
        printf("수행할 기능을 입력하세요.\n");
        scanf("%d", &op);
        getchar();
        
        switch(op) {
            case 1 :
                printf("몇번째 삼각수를 구하십니까? ");
                scanf("%d", &num);
                getchar();
                printf("%d\n\n", find_triangular(num));
                break;
            case 2 :
                printf("각 자릿수를 출력할 정수를 입력하시오: ");
                scanf("%d", &num);
                getchar();
                show_digit(num);
                printf("\n\n");
                break;
            case 3 :
                return 0;
                break;
            default:
                printf("잘못된 입력입니다.\n\n");
        }
    }
    
    
    
    return 0;
}

int find_triangular(int num) {
    if(num==1) {
        return 1;
    }
    
    else {
        return num + find_triangular(num-1);
    }
}

void show_digit(int num) {
    if(num/10==0) {
        printf("%d ", num);
    }
    
    else {
        show_digit(num/10);
        printf("%d ", num%10);
    }
}
