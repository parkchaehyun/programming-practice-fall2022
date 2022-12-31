//
//  main.c
//  final_project
//
//  Created by Chaehyun Park on 2022/12/19.
//

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int score=0, current_combo=0, max_combo=0;

int getch(void);

void initialize_board(int a[4][4]);
void print_board(int a[4][4]);
void check_clear(int a[4][4]);
void move_up(int a[4][4]);
void move_down(int a[4][4]);
void move_left(int a[4][4]);
void move_right(int a[4][4]);
void add_2_or_4(int a[4][4]);
void success_or_failure(int a[4][4]);

int main(void) {
    int a[4][4]={0, };
    char c;
    int menu;
    
    while(1){
        printf("2048\n");
        printf("1. Start game\n");
        printf("2. How to play\n");
        printf("3. Exit\n");
        printf("Choose menu: ");
        
        scanf("%d", &menu);
        getchar();
        
        printf("\n\n");
        
        if(menu==1){
            initialize_board(a);
            print_board(a);
            
            while(1){
                c=getch();
                
                switch(c){
                    case 'w':
                        move_up(a);
                        break;
                    case 's':
                        move_down(a);
                        break;
                    case 'a':
                        move_left(a);
                        break;
                    case 'd':
                        move_right(a);
                        break;
                    default:
                        printf("잘못된 입력입니다\n");
                }
                
                success_or_failure(a);
            }
        }
        
        if(menu==2){
            printf("Use 'w', 'a', 's', 'd' to move the tiles up, down, left or right. Tiles with the same number merge into one when they touch. Add them up to reach 2048!\n\n");
            
        }
        
        if(menu==3){
            exit(1);
        }
    }
    
    return 0;
}



int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}


void initialize_board(int a[4][4]){
    int i, j;
    
    srand(time(NULL));
    
    i=rand()%4;
    j=rand()%4;
    
    a[i][j]=2;
    
    while(1){
        i=rand()%4;
        j=rand()%4;
        
        if(a[i][j]==0){
            a[i][j]=4;
            break;
        }
    }
}




void print_board(int a[4][4]){
    int i, j;
    printf("SCORE: %d\tCURRENT COMBO: %d\tMAX COMBO: %d\n\n", score, current_combo, max_combo);

    printf("--------------------------\n");
    
    for (i=0; i<=3; i++) {
        printf("|");
        for (j=0; j<=3; j++) {
                printf("%4d  ", a[i][j]);
        }
        printf("|\n");
    }
    
    
    printf("--------------------------\n");
}


void add_2_or_4(int a[4][4]){
    int k;
    int i, j;
    
    srand(time(NULL));

    k=rand()%8;
    
    while(1){
        i=rand()%4;
        j=rand()%4;
        
        if(a[i][j]==0){
            if(k==7){
                a[i][j]=4;
            }
            else{
                a[i][j]=2;
            }
            break;
        }
    }
    
    
}


void move_up(int a[4][4]){
    int merge=0;
    int c[4][4];
    int change=0;
    int i, j, k;
    int b[4]= {0};
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c[i][j]=a[i][j];
        }
    }
    
    for(j=0;j<4;j++){
        for(i=0;i<3;i++){
            if(a[i][j]!=0){
                k=i+1;
                while(a[k][j]==0&&k<3){
                    k++;
                }
                if(a[i][j]==a[k][j]){
                    score+=a[i][j]*2;
                    a[i][j]*=2;
                    a[k][j]=0;
                    merge=1;
                }
            }
        }
    }
    
    for(j=0;j<4;j++){
        k=0;
        for(i=0;i<4;i++){
            b[i]=0;
        }
        
        for(i=0;i<4;i++){
            if(a[i][j]!=0){
                b[k++]=a[i][j];
            }
            a[i][j]=0;
        }
        
        for(i=0; i<4; i++){
            a[i][j]=b[i];
        }
        
        printf("\n");
    }
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]!=c[i][j]){
                change=1;
                break;
            }
        }
    }
    
    if(change==1){
        add_2_or_4(a);
    }
    
    if(merge==1){
        current_combo+=1;
        if(max_combo<current_combo){
            max_combo=current_combo;
        }
    }
    
    else{
        if(change!=0){
            current_combo=0;
        }
    }
    
    system("clear");
    
    print_board(a);
}


void move_down(int a[4][4]){
    int merge=0;
    int c[4][4];
    int change=0;
    int i, j, k;
    int b[4]= {0};
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c[i][j]=a[i][j];
        }
    }
    
    for(j=0;j<4;j++){
        for(i=3;i>0;i--){
            if(a[i][j]!=0){
                k=i-1;
                while(a[k][j]==0&&k>0){
                    k--;
                }
                if(a[i][j]==a[k][j]){
                    score+=a[i][j]*2;
                    a[i][j]*=2;
                    a[k][j]=0;
                    merge=1;
                }
            }
        }
    }
    
    for(j=0;j<4;j++){
        k=3;
        for(i=0;i<4;i++){
            b[i]=0;
        }
        
        for(i=3;i>=0;i--){
            if(a[i][j]!=0){
                b[k--]=a[i][j];
            }
            a[i][j]=0;
        }
        
        for(i=0; i<4; i++){
            a[i][j]=b[i];
        }
        
        printf("\n");
    }
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]!=c[i][j]){
                change=1;
                break;
            }
        }
    }
    
    if(change==1){
        add_2_or_4(a);
    }
    
    if(merge==1){
        current_combo+=1;
        if(max_combo<current_combo){
            max_combo=current_combo;
        }
    }
    
    else{
        if(change!=0){
            current_combo=0;
        }
    }
    
    system("clear");
    
    print_board(a);
    
}


void move_left(int a[4][4]){
    int merge=0;
    int c[4][4];
    int change=0;
    int i, j, k;
    int b[4]= {0};
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c[i][j]=a[i][j];
        }
    }
    
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            if(a[i][j]!=0){
                k=j+1;
                while(a[i][k]==0&&k<3){
                    k++;
                }
                if(a[i][j]==a[i][k]){
                    score+=a[i][j]*2;
                    a[i][j]*=2;
                    a[i][k]=0;
                    merge=1;
                }
            }
        }
    }
    
    for(i=0;i<4;i++){
        k=0;
        for(j=0;j<4;j++){
            b[j]=0;
        }
        
        for(j=0;j<4;j++){
            if(a[i][j]!=0){
                b[k++]=a[i][j];
            }
            a[i][j]=0;
        }
        
        for(j=0; j<4; j++){
            a[i][j]=b[j];
        }
        
        printf("\n");
    }
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]!=c[i][j]){
                change=1;
                break;
            }
        }
    }
    
    if(change==1){
        add_2_or_4(a);
    }
    
    if(merge==1){
        current_combo+=1;
        if(max_combo<current_combo){
            max_combo=current_combo;
        }
    }
    
    else{
        if(change!=0){
            current_combo=0;
        }
    }
    
    system("clear");
    
    print_board(a);
}



void move_right(int a[4][4]){
    int merge=0;
    int c[4][4];
    int change=0;
    int i, j, k;
    int b[4]= {0};
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            c[i][j]=a[i][j];
        }
    }
    
    for(i=0;i<4;i++){
        for(j=3;j>0;j--){
            if(a[i][j]!=0){
                k=j-1;
                while(a[i][k]==0&&k>0){
                    k--;
                }
                if(a[i][j]==a[i][k]){
                    score+=a[i][j]*2;
                    a[i][j]*=2;
                    a[i][k]=0;
                    merge=1;
                }
            }
        }
    }
    
    for(i=0;i<4;i++){
        k=3;
        for(j=0;j<4;j++){
            b[j]=0;
        }
        
        for(j=3;j>=0;j--){
            if(a[i][j]!=0){
                b[k--]=a[i][j];
            }
            a[i][j]=0;
        }
        
        for(j=0; j<4; j++){
            a[i][j]=b[j];
        }
        
        printf("\n");
    }
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]!=c[i][j]){
                change=1;
                break;
            }
        }
    }
    
    if(change==1){
        add_2_or_4(a);
    }
    
    if(merge==1){
        current_combo+=1;
        if(max_combo<current_combo){
            max_combo=current_combo;
        }
    }
    
    else{
        if(change!=0){
            current_combo=0;
        }
    }
    
    system("clear");
    
    print_board(a);
}

void success_or_failure(int a[4][4]){
    int i, j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]==2048){
                printf("\nGAME CLEAR!\n\n");
                exit(1);
            }
        }
    }

    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(a[i][j]==0){
                return;
            }
        }
    }
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==a[i+1][j]){
                return;
            }
            
            if(a[i][j]==a[i][j+1]){
                return;
            }
        }
    }
    
    if(a[0][3]==a[1][3] || a[1][3]==a[2][3] || a[2][3]==a[3][3]){
        return;
    }
    
    if(a[3][0]==a[3][1] || a[3][1]==a[3][2] || a[3][2]==a[3][3]) {
        return;
    }
    
    printf("\nGAME OVER!\n\n");
    exit(1);
    
}
