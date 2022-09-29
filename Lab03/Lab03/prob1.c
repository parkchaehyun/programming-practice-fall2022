#include <stdio.h>

int main(void) {
    
    int x, y;
    
    printf("x좌표, y좌표를 입력해주세요: ");
    scanf("%d %d", &x, &y);
    
    (x>0 && y>0) ? printf("1사분면\n") : (y>0) ? printf("2사분면\n") : (x<0) ? printf("3사분면\n") : printf("4사분면\n");
    return 0;
}
