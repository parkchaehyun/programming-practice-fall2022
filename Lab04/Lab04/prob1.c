#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c;
    
    printf("계수 a를 입력하시오: ");
    scanf("%lf", &a);
    getchar();
    
    printf("계수 b를 입력하시오: ");
    scanf("%lf", &b);
    getchar();
    
    printf("계수 c를 입력하시오: ");
    scanf("%lf", &c);
    
    if(a==0) {
        printf("방정식의 근은 %f입니다.\n", -c/b);
    }
    
    else{
        if(b*b-4*a*c<0){
            printf("실근이 존재하지 않습니다.\n");
        }
        
        else{
            printf("방정식의 근은 %f입니다.\n", (-b+sqrt(b*b-4*a*c))/(2*a));
            printf("방정식의 근은 %f입니다.\n", (-b-sqrt(b*b-4*a*c))/(2*a));
        }
    }
    
    
    
    return 0;
}
