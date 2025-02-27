#include <stdio.h>

int calculateFirstDayOfYear(int year) {
    int q = 1;  // 1st day of the month
    int m = 13; // January is treated as month 13 of the previous year
    int K = (year - 1) % 100; // Last two digits of the previous year
    int J = (year - 1) / 100; // First two digits (century part) of the previous year

    int h = (q + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;

    return h; // 0 = Saturday, 1 = Sunday, ..., 6 = Friday
}


int main() {

    char *months[] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int dayInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, w, weekday=0, spaceCounter=0, year;


    printf("Enter your favorite year\n");
    scanf("%d", &year);

    printf("\n\n============== Welcome To %d =============\n\n", year);

    // calculate leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        dayInMonths[1] = 29;
    }

    // get the first day of the year
    weekday = calculateFirstDayOfYear(year);

    for(i = 0; i < 12; i++) {
        printf("\n\n.................   %s  ...................\n\n", months[i]);
        printf("\n   Sat   Sun   Mon   Tue   Wed   Thu   Fri   \n\n");

        for(int spaceCounter=1; spaceCounter <= weekday; spaceCounter++){
            printf("      ");
        }
        int totalDay = dayInMonths[i];
        for(j = 1; j <= totalDay ; j++) {
            printf("%6d", j);

            weekday++;
            if(weekday > 6){
                printf(" \n");
                weekday=0;
            }
        }

    }

    return 0;
}
