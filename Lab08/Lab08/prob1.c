#include <stdio.h>
#include <stdlib.h>

void input(int n);
void output(int n, char[]);

int main(void) {
    int n;
    printf("Enter the size:\n");
    printf(">>");
    scanf("%d", &n);
    input(n);

    return 0;
}

void input(int n) {
    char data[n];
    printf("String pattern : ");
    scanf("%s", data);
    
    for(int i=0;i<n;i++) {
        if(data[i]<33||data[i]>126) {
            printf("data out of range\n");
            exit(0);
        }
    }
    
    output(n, data);
}

void output(int n, char data[]) {
    int i,j,space,k;
    space=n+3;
        for(i=1;i<=n;i++) {
            for(k=space;k>=1;k--) {
                printf(" ");
            }
            
            for(j=0;j<i;j++) {
                printf("%c ", data[j]);
            }
            
            printf("\n");
            space--;
        }
}

