#include <stdio.h>

int main(void) {
    
    int r;
    double pi=3.14;
    double d;
    
    
    scanf("%d", &r);
    
    d=2*pi*r;
    
    printf("원의 둘레는 %.2lf 입니다.\n", d);
    
    return 0;
}
