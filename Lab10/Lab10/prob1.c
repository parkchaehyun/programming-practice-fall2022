#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct data {
    char id[7];
    char name[20];
    int work_hour;
    int hourly_wage;
    float total_wage;
    int len;

} DATA;

void print_all_employees(DATA *d, int len);
void print_single_employee(DATA *d, int len);
void print_all_employees_sorted_by_name(DATA *d, int len);
void print_total_work_hour_and_wage(DATA *d, int len);
void add_new_employee(DATA *d, int len);


int main(void) {
    int loop=1;
    int i;
    char menu;
    int len = 0;

    DATA d[20]= {
        {"ASD111", "홍길동", 43, 24500, 0},
        {"ASD121", "장세길", 38, 27000, 0},
        {"ASD125", "최수종", 13, 35000, 0},
        {"BFD001", "김기수", 62, 40000, 0},
        {"BFD111", "이기자", 55, 32500, 0},
        {"BFD112", "문길열", 23, 42500, 0},
        {"BFD121", "박미석", 41, 26500, 0},
        {"CSD011", "홍성자", 27, 31500, 0},
        {"CSD111", "이미영", 68, 26000, 0},
        {"CSD117", "김수동", 45, 55000, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
        {"", "", 0, 0, 0},
    };
    
    
    
    for (i=0;i<10;i++) {
        if(d[i].work_hour > 40) {
            d[i].total_wage+= (float)40*(float)d[i].hourly_wage/10000;

            d[i].total_wage+= (float)(d[i].work_hour-40)*(float)d[i].hourly_wage*1.5/10000;
        }
        
        else {
            d[i].total_wage = (float)d[i].work_hour*(float)d[i].hourly_wage/10000;
        }
    }
    
    
    for (i=0;i<41;i++) {
        printf("*");
    }
    printf("\n");
    printf("* A:a. 사원 전체 정보 출력\t\t*\n");
    printf("* B:b. 특정 사원 정보 출력\t\t*\n");
    printf("* C:c. 사원명에 의한 정렬\t\t*\n");
    printf("* D:d. 전체 근무시간과 총 지급액\t*\n");
    printf("* E:e. 새 사원의 추가\t\t\t*\n");
    printf("* Q:q. 종료\t\t\t\t*\n");
    for (i=0;i<41;i++) {
        printf("*");
    }
    printf("\n\n");

while(loop==1){
        printf("Menu를 선택하세요<A~E> : ");
        scanf("%c", &menu);
        getchar();
    
        menu = tolower(menu);
    
    
        for(i=0;i<20;i++) {
            if(strcmp(d[i].id,"")==0) {
                len = i;
                break;
            }
            
            else if (i==19) {
                len=20;
            }
        }
            
    
        switch(menu) {
            case 'a' :
                print_all_employees(d, len);
                break;
            case 'b' :
                print_single_employee(d, len);
                break;
            case 'c' :
                print_all_employees_sorted_by_name(d, len);
                break;
            case 'd' :
                print_total_work_hour_and_wage(d, len);
                break;
            case 'e' :
                add_new_employee(d, len);
                break;
            case 'q' :
                return 0;
            default:
                printf("잘못된 입력입니다.\n\n");
                
        }
        
}

    
    return 0;
}

void print_all_employees(DATA *d, int len) {
    int i;
    
    printf("\n%10s\t%-10s\t%10s\t%10s\t%20s\n", "사원번호", "성명", "근무시간", "시간당임", "총급여<단위:만>");
    for(i=0;i<80;i++) {
        printf("=");
    }
    printf("\n");
    
    for(i=0;i<len;i++) {
        printf("%s\t\t", d[i].id);
        printf("%s\t\t", d[i].name);
        printf("%d\t\t", d[i].work_hour);
        printf("%d\t\t", d[i].hourly_wage);
        printf("%6.2f\n", d[i].total_wage);
    }
    for(i=0;i<80;i++) {
        printf("=");
    }
    printf("\n\n\n");
}

void print_single_employee(DATA *d, int len) {
    int i;
    char name[20];
    
    printf("검색할 사원을 입력하세요 : ");
    scanf("%s", name);
    getchar();
    
    for(i=0;i<len;i++) {
        if(strcmp(d[i].name, name)==0) {
            break;
        }
    }

    if(i==len) {
        printf("해당 사원이 존재하지 않음\n");
    }
    
    else {
        printf("%-15s: %s\n", "사원명", d[i].name);
        printf("%-16s: %d\n", "근무시간", d[i].work_hour);
        printf("%-17s: %d\n", "시간당 임금", d[i].hourly_wage);
        printf("%-15s: %6.2f<만원>\n", "총임금", d[i].total_wage);
    }
    
}

void print_all_employees_sorted_by_name(DATA *d, int len) {
    DATA sorted_d[20];
    DATA temp;
    int i, k;
    
    for(i=0;i<len;i++){
        sorted_d[i]=d[i];
    }
    
    for(i=0;i<len-1;i++){
        for(k=0;k<len-1;k++){
            if(strcmp(sorted_d[k].name, sorted_d[k+1].name)>0) {
                temp=sorted_d[k];
                sorted_d[k]=sorted_d[k+1];
                sorted_d[k+1]=temp;
            }
        }
    }
    
    print_all_employees(sorted_d, len);
    
}

void print_total_work_hour_and_wage(DATA *d, int len) {
    int i;
    int total_hour=0;
    int total_wage=0;
    
    for(i=0;i<len;i++){
        total_hour+=d[i].work_hour;
        total_wage+=d[i].total_wage*10000;
    }
    
    printf("%-15s: %15d\n", "총 근무 시간", total_hour);
    printf("%-15s: %14d원\n", "총 지불 임금", total_wage);
}

void add_new_employee(DATA *d, int len){
    DATA to_add;
    
    printf("추가할 사원ID를 입력 : ");
    scanf("%s", to_add.id);
    getchar();
    printf("추가할 사원명을 입력 : ");
    scanf("%s", to_add.name);
    getchar();
    printf("근무시간 입력 : ");
    scanf("%d", &to_add.work_hour);
    getchar();
    printf("시간당 임금 입력 : ");
    scanf("%d", &to_add.hourly_wage);
    getchar();
    
    if(to_add.work_hour > 40) {
        to_add.total_wage+= (float)40*(float)to_add.hourly_wage/10000;

        to_add.total_wage+= (float)(to_add.work_hour-40)*(float)to_add.hourly_wage*1.5/10000;
    }
    
    else {
        to_add.total_wage = (float)to_add.work_hour*(float)to_add.hourly_wage/10000;
    }
    
    d[len]=to_add;

    printf("\n\n");
}
