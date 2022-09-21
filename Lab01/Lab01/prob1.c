#include <stdio.h>

int main(void) {
    
    int angle_1;
    int angle_2;
    
    scanf("%d %d", &angle_1, &angle_2);
    
    printf("세 번째 각은: %d\n", (180-angle_1-angle_2));
    
    return 0;
}
