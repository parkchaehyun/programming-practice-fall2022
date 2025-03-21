#include <stdio.h>


int main(void){
    
    printf("%d\n", 7 / 3);
    printf("%lu\n", sizeof(7 / 3));
    
    printf("%f %lu\n", 7 / 3.0f, sizeof(7 / 3.0f));
    printf("%lf\n%lu\n", 7 / 3.0, sizeof(7 / 3.0));
    printf("%f %lu\n", (float)7 / 3.0, sizeof((float)7 / 3.0));
    
    printf("%d %lld\n", 1000000000 * 10 / 10, (long long)1000000000 * 10 / 10);
    printf("%lu\n", sizeof((long long)2019));
    
    printf("%d %d %lu %lu\n", 'A' * 2, (char)'A' * 2, sizeof('A'), sizeof((char)'A'));
    printf("%c %c\n", 5 * 13, 291 / 3);
    printf("%d %d %d\n", 1 * 2, '1' * 2, 1 * '2');
    
    return 0;
}
