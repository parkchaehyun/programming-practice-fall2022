#include <stdio.h>

int main(void){
    int y;
    
    printf("년도를 입력하시오\n");
    scanf("%d", &y);
    
    if(y%4==0) {
        if(y%100==0) {
            if(y%400==0) {
                printf("입력하신 년도는 윤년입니다.\n");
            }
            
            else {
            printf("입력하신 년도는 윤년이 아닙니다.\n");
            }
        }
        
        else{
            printf("입력하신 년도는 윤년입니다.\n");
        }
    }
    
    else {
        printf("입력하신 년도는 윤년이 아닙니다.\n");
    }
    
    
    return 0;
}
