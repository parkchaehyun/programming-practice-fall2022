#include <stdio.h>

#define min 60

int main(void) {
    double light_speed = 300000;
    double distance = 149600000;
    
    double time;
    int time_min, time_sec;
    
    time = distance / light_speed;
    
    time_min = time / min;
    time_sec = (int)time % min;
    
    printf("Speed of light: %fkm/s\n", light_speed);
    printf("Distance between sun and earth: %fkm\n", distance);
    printf("Arrival time: %dmin %dsec\n", time_min, time_sec);
    
    
    return 0;
}
