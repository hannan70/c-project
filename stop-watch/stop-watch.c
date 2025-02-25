#include <stdio.h>
#define CYCLE 5
#include <windows.h>
#include <conio.h>

void clearScreen() {
    system("cls");  // Windows clear screen command
}

int main() {

    int hour, minute, second;
    printf("Enter Hour, Minute, Second\n");
    scanf("%d%d%d", &hour, &minute, &second);

    int h=0, m=0, s=0;
    clearScreen();

    while(1) {

        printf("@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("     %.2d:%.2d:%.2d:     \n", h, m, s);

        printf("@@@@@@@@@@@@@@@@@@@@@@\n");

        if(h==hour && m==minute && second==s){
            break;
        }


        Sleep(1000); // 1 second
        clearScreen();


         s++;
        // Update minute
        if(s==CYCLE){
            m++;
            s = 0;
        }

        // Update hour
        if(m==CYCLE) {
            h++;
            m = 0;
        }
    }



    return 0;
}
