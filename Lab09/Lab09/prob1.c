#include <stdio.h>

void square(int *pn);
void swap(int *pa, int *pb);

int main(void) {
    int x=1;
    double y=2;
    int *px=&x;
    double *py=&y;
    int n=0;
    int a, b;
    
    printf("x=%d, px=%p\n", x, px);
    (*px)++;
    printf("x=%d, px=%p\n", x, px);
    
    printf("y=%f, py=%p\n", y, py);
    (*py)++;
    printf("y=%f, py=%p\n", y, py);
    
    printf("x=%d, px=%p\n", x, px);
    *px++;
    printf("x=%d, px=%p\n", x, px);

    printf("y=%f, py=%p\n", y, py);
    *py++;
    printf("y=%f, py=%p\n", y, py);
    
    
    square(&n);
    
    
    printf("숫자 1: ");
    scanf("%d", &a);
    printf("숫자 2: ");
    scanf("%d", &b);
    
    printf("바꾸기 전\n");
    printf("숫자 1: %d, 숫자 2: %d\n", a, b);
    
    swap(&a, &b);
    
    printf("바꾼 후\n");
    printf("숫자 1: %d, 숫자 2: %d\n", a, b);

    
    return 0;
}


void square(int *pn){
    int input;
    printf("숫자 입력: ");
    scanf("%d", &input);
    
    *pn=input*input;
    
    printf("제곱: %d\n", *pn);
}

void swap(int *px, int *py){
    int temp;
    
    temp = *px;
    *px = *py;
    *py= temp;
}
