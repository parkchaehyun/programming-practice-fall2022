//
//  main.c
//  Lab11
//
//  Created by Chaehyun Park on 2022/11/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[20];
    char address[100];
    char phone_number[20];
    char characteristic[50];
} PERSON;

PERSON get_record(void);
void add_record(FILE *fp);
void update_record(FILE *fp);
void search_record(FILE *fp);
void print_record(PERSON data);


int main(void) {
    int i, menu;
    FILE *fp = NULL;
    
    if((fp=fopen("address.dat", "ab+")) == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.");
        exit(1);
    }
    
    
    for (i=0;i<20;i++) {
        printf("=");
    }
    printf("\n");
    
    printf("1. 추가\n");
    printf("2. 수정\n");
    printf("3. 검색\n");
    printf("4. 종료\n");
    
    for (i=0;i<20;i++) {
        printf("=");
    }
    printf("\n");
    
    while(1){
            printf("메뉴를 선택하세요: ");

            scanf("%d", &menu);
        
            switch(menu) {
                case 1 :
                    add_record(fp);
                    break;
                case 2 :
                    update_record(fp);
                    break;
                case 3 :
                    search_record(fp);
                    break;
                case 4 :
                    fclose(fp);
                    exit(1);
                default:
                    printf("잘못된 입력입니다.\n\n");
            }
            
    }
    
    
    return 0;
}


PERSON get_record(void){
    PERSON data;
    
    fflush(stdin);
    
    printf("이름: ");
    scanf("%s", data.name);
    
    printf("주소: ");
    scanf("%s", data.address);
    
    printf("휴대폰: ");
    scanf("%s", data.phone_number);
    
    printf("특징: ");
    scanf("%s", data.characteristic);
    
    return data;
}


void add_record(FILE *fp) {
    PERSON data;
    
    data = get_record();
    
    fseek(fp, 0L, SEEK_END);
    fwrite(&data, sizeof(PERSON), 1, fp);
}

void update_record(FILE *fp){
    char name[20];
    int  found = 0;
    PERSON data;
    PERSON update_data;
    FILE *fp_2 = NULL;
    if((fp_2=fopen("address2.dat", "ab+")) == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다.");
        exit(1);
    }
    
    
    
    fseek(fp, 0L, SEEK_SET);

    fflush(stdin);
    
    printf("검색할 이름: ");
    scanf("%s", name);
    
    
    while(!feof(fp)) {
        fread(&data, sizeof(PERSON), 1, fp);
        
        if(strcmp(data.name, name)==0) {
            if(found==1) {
                break;
            }

            found=1;
            
            strcpy(update_data.name, name);
            
            printf("수정할 주소: ");
            scanf("%s", update_data.address);
            
            printf("수정할 휴대폰: ");
            scanf("%s", update_data.phone_number);
            
            printf("수정할 특징: ");
            scanf("%s", update_data.characteristic);
            
            fseek(fp_2, 0L, SEEK_END);
            fwrite(&update_data, sizeof(PERSON), 1, fp_2);
        }
        
        else{
            fseek(fp_2, 0L, SEEK_END);
            fwrite(&data, sizeof(PERSON), 1, fp_2);
        }
    }
    
    fclose(fp_2);
    fclose(fp);
    
    if(found==0) {
        printf("수정할 사람을 찾지 못했습니다.\n");
        remove("address2.dat");
    }
    
    else {
        remove("address.dat");
        rename("address2.dat", "address.dat");
        fp=fopen("address.dat", "ab+");
    }
    
    
    
}

void search_record(FILE *fp) {
    char name[20];
    int found=0;
    PERSON data;
    
    fseek(fp, 0L, SEEK_SET);

    fflush(stdin);
    
    printf("검색할 이름: ");
    scanf("%s", name);
    
    while(!feof(fp)) {
        fread(&data, sizeof(PERSON), 1, fp);
        if(strcmp(data.name, name)==0) {
            print_record(data);
            found=1;
            break;
        }
    }
    
    if(found==0) {
        printf("해당 사람을 찾지 못했습니다.\n");
    }
    
}

void print_record(PERSON data){
    printf("이름: %s\n", data.name);
    
    printf("주소: %s\n", data.address);
    
    printf("휴대폰: %s\n", data.phone_number);
    
    printf("특징: %s\n", data.characteristic);
}
