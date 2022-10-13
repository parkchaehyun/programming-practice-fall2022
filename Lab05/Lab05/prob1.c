#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    srand(time(0));
    
    int n = 100;
    int num = (rand()%n)+1;
    int guess=-1;
    int tries=0;
    
    while(guess!=num){
        printf("정답을 추측하여 보시오: ");
        scanf("%d", &guess);
        
        (guess==num) ? : (guess>num) ? printf("제시한 정수가 높습니다.\n") : printf("제시한 정수가 낮습니다.\n");
        
        tries++;
    }
    
    printf("축하합니다.시도횟수=%d\n", tries);
    
    return 0;
}
