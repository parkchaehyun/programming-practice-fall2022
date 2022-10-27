#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 6

void get_dice_face(void);

int main(void) {
    srand(time(0));
    
    char c;
    
    for(int i=0; i<100; i++) {
        get_dice_face();
        
        if(i==99) {
            printf("계속 하시겠습니까? (y-계속, n-종료) : ");
            scanf("%c", &c);
            getchar();
            if(c=='y')
            {
                i=-1;
            }
        }
    }
    
    return 0;
}

void get_dice_face(void) {
    static int face_1 = 0;
    static int face_2 = 0;
    static int face_3 = 0;
    static int face_4 = 0;
    static int face_5 = 0;
    static int face_6 = 0;

    
    int num = (rand()%NUM)+1;
    
    switch(num) {
        case 1 :
            face_1+=1;
            break;
        case 2 :
            face_2+=1;
            break;
        case 3 :
            face_3+=1;
            break;
        case 4 :
            face_4+=1;
            break;
        case 5 :
            face_5+=1;
            break;
        case 6 :
            face_6+=1;
            break;
        default:
            break;
    }
    
    if((face_1+face_2+face_3+face_4+face_5+face_6)%100==0){
        printf("1\t2\t3\t4\t5\t5\n");
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", face_1, face_2, face_3, face_4, face_5, face_6);
    }
}
