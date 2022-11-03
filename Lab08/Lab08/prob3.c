#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board(char board[][3]);
int get_player_move(char board[][3]);
int get_computer_move(char board[][3]);
void disp_board(char board[][3]);
int check_victory(char board[][3]);


int main(void) {
    char board[3][3];
    int quit=0;
    init_board(board);
    disp_board(board);
    
    while(1){
        quit = get_player_move(board);
        if(quit==-1) {
            break;
        }
        
        disp_board(board);
        
        if(quit==1) {
            printf("Player wins!\n");
            break;
        }
        quit = get_computer_move(board);
        disp_board(board);
        if(quit==1) {
            printf("Computer wins!\n");
            break;
        }
    }
    
    return 0;
}

void init_board(char board[][3]) {
    int x,y;
    for(x=0; x<3; x++) {
        for(y=0; y<3; y++) {
            board[x][y] = ' ';
        }
        
    }
}

void disp_board(char board[3][3]){
    int i;
    for(i=0;i<3;i++){
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    }
    printf("---|---|---\n");
    
}

int get_player_move(char board[3][3]) {
    int x=0, y=0, done = 0;
    
    while(done!=1) {
        printf("(x,y) 좌표 (종료: -1, -1): ");
        scanf("%d %d", &x, &y);
        
        if(x==-1&&y==-1) {
            return -1;
        }
        
        if(board[x][y]== ' ') {
            break;
        }
        
        else{
            printf("잘못된 위치입니다.\n");
        }
    }
    
    board[x][y] = 'X';
    
    done=check_victory(board);
    
    return done;
}

int get_computer_move(char board[3][3]) {
    int x=0, y=0, done = 0;
    srand(time(0));
    
    while(done!=1) {
        x=rand()%3;
        y=rand()%3;
        
        if(board[x][y]== ' ') {
            break;
        }
    }
    
    board[x][y] = 'O';
    
    done=check_victory(board);
    
    return done;
}

int check_victory(char board[3][3]) {
    int i, j, k, vic=0;
    
    int x,y;
    for(x=0; x<3; x++) {
        vic=0;
        for(y=0; y<3; y++) {
            if(board[x][y]=='O'){
                vic+=1;
            }
            
            else if(board[x][y]=='X'){
                vic-=1;
            }
            if(vic==3||vic==-3) {
                return 1;
            }
        }
    }
    
    for(y=0; y<3; y++) {
        vic=0;
        for(x=0; x<3; x++) {
            if(board[x][y]=='O'){
                vic+=1;
            }
            
            else if(board[x][y]=='X'){
                vic-=1;
            }
            if(vic==3||vic==-3) {
                return 1;
            }
        }
    }
    
    vic=0;
    
    for(k=0;k<3;k++){
        x=k;
        y=k;
        
        if(board[x][y]=='O'){
            vic+=1;
        }
        
        else if(board[x][y]=='X'){
            vic-=1;
        }
        if(vic==3||vic==-3) {
            return 1;
        }
    }
    
    vic=0;
    
    for(k=0;k<3;k++){
        x=k;
        y=2-k;
        
        if(board[x][y]=='O'){
            vic+=1;
        }
        
        else if(board[x][y]=='X'){
            vic-=1;
        }
        if(vic==3||vic==-3) {
            return 1;
        }
    }
    
    return 0;
}
