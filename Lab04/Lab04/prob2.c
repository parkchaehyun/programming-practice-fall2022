#include <stdio.h>
#include <math.h>

int main(void){
    double a, b, c;
    char o;
    
    printf("수식을 입력하시오(예: 2+5)\n");
    
    scanf("%lf %c %lf", &a, &o, &b);
    
    switch(o) {
        case '+':
            c = a + b;
            break;
            
        case '-':
            c = a - b;
            break;
            
        case 'x':
            c = a * b;
            break;
            
        case '/':
            if(b==0) {
                printf("0으로 나눌 수 없습니다.\n");
                return 0;
            }
            
            else {
                c = a / b;
                break;
            }
    
        case '%':
            c = fmod(a, b);
            break;
            
        default:
            printf("지원되지 않는 연산자입니다.\n");
            return 0;
    }
    
    printf("%g%c%g=%g\n", a, o, b, c);
    
    return 0;
}
