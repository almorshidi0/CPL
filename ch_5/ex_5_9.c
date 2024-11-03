#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    
    if((year < 1) || (month < 1) || (month > 12))
        return -1;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if((day < 1) || (day > *(*(daytab + leap) + month)))
        return -1;
    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if(year < 1){
        *pmonth = -1;
        return;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if((yearday < 1) || (yearday > (365 + leap))){
        *pmonth = -1;
        return;
    }
    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}

int main() {
    int year, month, day, yearday;
    int pmonth, pday;

    // Get date input from user
    printf("Enter year, month, and day (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);
    
    // Calculate day of the year
    yearday = day_of_year(year, month, day);
    if(yearday == -1){
        printf("Error\n");
        return -1;
    }
    printf("Day of the year: %d\n", yearday);

    // Convert back from day of the year to month and day
    month_day(year, yearday, &pmonth, &pday);
    if((pmonth == -1) || (pday == -1)){
        printf("Error\n");
        return -1;
    }
    printf("Converted back: Month: %d, Day: %d\n", pmonth, pday);

    return 0;
}