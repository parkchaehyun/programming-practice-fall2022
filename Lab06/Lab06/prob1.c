#include <stdio.h>

char input_char(void);
int input_int(void);
void output(char, int);

int main(void) {

    char c = input_char();
    int n = input_int();
    
    output(c, n);
    
    return 0;
}

char input_char(void) {
    
    char c;
    
    printf("표현문자를 입력하세요\n");
    scanf("%c", &c);
    getchar();
    
    return c;
}

int input_int(void) {
    
    int n;
    
    printf("크기를 입력하세요\n");
    scanf("%d", &n);
    
    return n;
}

void output(char c, int n) {
    int p;
    
    for(int i=0;i<n;i++){
        if(i<(n/2)+1)
            p=i;
        else
            p=n-i-1;
        
        int q=(n-(2*p+1))/2;
        
        for(int j=0;j<q;j++){
            printf(" ");
        }
        
        for(int k=0;k<(2*p+1);k++){
            printf("%c", c);
        }
        
        for(int m=0;m<q;m++){
            printf(" ");
        }
        
        printf("\n");
    }
    
}
