#include <stdio.h>

int isLeapYear(int year) {
    
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void getNextDate(int *day, int *month, int *year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (*day < 1 || *day > 31 || *month < 1 || *month > 12 || *year < 1) {
        printf("Invalid date input.\n");
        return;
    }

    
    if (isLeapYear(*year)) {
        daysInMonth[2] = 29; 
    }

    
    if (*day > daysInMonth[*month]) {
        printf("Invalid date input.\n");
        return;
    }

    
    (*day)++;
    
    
    if (*day > daysInMonth[*month]) {
        *day = 1;
        (*month)++;
        
        if (*month > 12) {
            *month = 1;
            (*year)++;
        }
    }
}

int main() {
    int day, month, year;

    
    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    
    getNextDate(&day, &month, &year);

    
    printf("The next date is: %02d-%02d-%04d\n", day, month, year);

    return 0;
}
