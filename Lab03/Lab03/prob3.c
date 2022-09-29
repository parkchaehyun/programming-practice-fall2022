#include <stdio.h>

int main(void) {
    unsigned int i=0;
    char a;
    
    printf("첫번째 문자: ");
    scanf("%c", &a);
    getchar();
    i+=a;
    i<<=8;
    
    printf("두번째 문자: ");
    scanf("%c", &a);
    getchar();
    i+=a;
    i<<=8;
    
    printf("세번째 문자: ");
    scanf("%c", &a);
    getchar();
    i+=a;
    i<<=8;
    
    printf("네번째 문자: ");
    scanf("%c", &a);
    i+=a;
    
    printf("%X\n", i);
    
    
    return 0;
}
