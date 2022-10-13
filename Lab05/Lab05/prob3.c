#include <stdio.h>

int main(void) {
    
    char c='0';
    
    while(c!='Q'){
        printf("소문자를 입력하시오: ");
        scanf("%c", &c);
        getchar();
        
        if(c>='a'&&c<='z') {
            c+='A'-'a';
            printf("변환된 대문자는 %c입니다.\n", c);
        }
        
        else if(c!='Q')
            printf("다시 입력하시오.\n");
        
    }
    return 0;
}
