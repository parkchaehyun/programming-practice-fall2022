#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAIL 2
#define LIMIT 3

static int super_id = 1234;
static int super_password = 5678;
static int id_try = 0;
static int password_try = 0;
static int balance = 0;

int check(int id, int password);
void save(int amount);
void draw(int amount);

int main(void) {
    
    int id, password, result;
    int option, money;
    
    while(1) {
        printf("ID와 password를 입력해주세요.\n");
        printf("ID: ");
        scanf("%d", &id);
        getchar();
        printf("PW: ");
        scanf("%d", &password);
        getchar();
        result = check(id, password);
        if(result==SUCCESS) {
            printf("로그인에 성공하였습니다.\n");
            break;
        }
    }
    
    while(1) {
        printf("메뉴를 선택하세요: 저축(1), 인출(2), 종료(3)\n");
        scanf("%d", &option);
        getchar();
        
        if(option==1) {
            printf("저축할 금액: ");
            scanf("%d", &money);
            getchar();
            save(money);
        }
        
        else if(option==2) {
            printf("인출할 금액: ");
            scanf("%d", &money);
            getchar();
            draw(money);
        }
        
        else if(option==3) {
            printf("은행 프로그램 종료\n");
            break;
        }
        
        else {
            printf("잘못 입력하셨습니다.\n");
        }
    }
    
    return 0;
}

int check(int id, int password) {
    if(id!=super_id) {
        id_try++;
        printf("ID가 일치하지 않습니다.\n");
        
        if(id_try>=LIMIT) {
            printf("입력 횟수가 초과하였습니다.\n");
            id_try=0;
            password_try=0;
        }
        
        return FAIL;
    }
    
    if(password!=super_password) {
        password_try++;
        printf("PW가 일치하지 않습니다.\n");
        
        if(password_try>=LIMIT) {
            printf("입력 횟수가 초과하였습니다.\n");
            id_try=0;
            password_try=0;
        }
        
        return FAIL;
    }
        
    return SUCCESS;
}

void save(int amount) {
    balance+=amount;
    printf("현재 잔액은 %d원입니다.\n", balance);
}
    
void draw(int amount) {
    if(amount>balance) {
        printf("잔액이 부족합니다.\n");
    }
    else {
        balance-=amount;
    }
    printf("현재 잔액은 %d원입니다.\n", balance);
}
