#include <stdio.h>

int main(void) {
    
    int x, y;
    
    printf("정수를 입력 하시오: ");
    scanf("%d", &x);
    printf("2를 곱하는 횟수: ");
    scanf("%d", &y);
    
    printf("%d<<%d의 값: %d\n", x, y, x<<y);
    
    return 0;
}
