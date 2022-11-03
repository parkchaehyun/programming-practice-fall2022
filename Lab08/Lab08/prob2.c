#include <stdio.h>


void set_days_in_month(int year);
int daycount(int year, int month, int day);
int which_month(int year, int days);
int which_day(int year, int days);
int leap_year(int year);

int days_in_month[12];

int main(void) {
    int year, month, day;
    int day_of_year;
    printf("Enter the first meeting day (YYYY MM DD)\n>>");
    scanf("%d %d %d", &year, &month, &day);
    set_days_in_month(year);
    day_of_year=daycount(year, month, day);
    printf("This day is the %d day of the year.\n", day_of_year);
    
    day_of_year+=99;
    
    if(day_of_year>365+leap_year(year)){
        day_of_year-=365+leap_year(year);
        year+=1;
        set_days_in_month(year);
    }
    
    printf("The 100th day is %d %d %d\n", year, which_month(year, day_of_year), which_day(year, day_of_year));

    return 0;
}


void set_days_in_month(int year) {
    days_in_month[0] = 31;
    if(leap_year(year)){
        days_in_month[1] = 29;
    }
    else{
        days_in_month[1] = 28;
    }
    days_in_month[2] = 31;
    days_in_month[3] = 30;
    days_in_month[4] = 31;
    days_in_month[5] = 30;
    days_in_month[6] = 31;
    days_in_month[7] = 31;
    days_in_month[8] = 30;
    days_in_month[9] = 31;
    days_in_month[10] = 30;
    days_in_month[11] = 31;
}


int daycount(int year, int month, int day) {
    int day_count=0;
    for(int i=0;i<month-1;i++) {
        day_count+=days_in_month[i];
    }
    day_count+=day;

    return day_count;
}

int which_month(int year, int days) {
    int i;
    for(i=0; i<12; i++) {
        days-=days_in_month[i];
        
        if(days<0) {
            break;
        }
    }
    
    return i+1;
}

int which_day(int year, int days) {
    int i;
    for(i=0; i<12; i++) {
        if(days-days_in_month[i]>0){
            days-=days_in_month[i];
        }
        
        else {
            break;
        }
    }
    
    return days;
}

int leap_year(int y) {
    if(y%4==0) {
            if(y%100==0) {
                    if(y%400==0) {
                        return 1;
                   }
            
                  else {
                    return 0;
                }
        
        }
        
            else {
                    return 1;
            }
        }
    
        else {
            return 0;
        }

}
