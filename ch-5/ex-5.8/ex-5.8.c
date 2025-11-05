#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: convert month & day into day of year with error checking */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month < 1 || month > 12) {
        printf("Error: invalid month %d\n", month);
        return -1;
    }
    if (day < 1 || day > daytab[leap][month]) {
        printf("Error: invalid day %d for month %d\n", day, month);
        return -1;
    }

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: convert day of year into month & day with error checking */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        printf("Error: invalid yearday %d\n", yearday);
        *pmonth = *pday = -1;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

/* main: test the date conversion functions */
int main(void)
{
    int year = 2024;
    int month = 3, day = 1;
    int yearday;
    int m, d;

    yearday = day_of_year(year, month, day);
    if (yearday != -1)
        printf("%d-%02d-%02d is day %d of year %d\n", year, month, day, yearday, year);

    month_day(year, yearday, &m, &d);
    if (m != -1)
        printf("Day %d of %d is %02d/%02d\n", yearday, year, m, d);

    /* Error checks */
    printf("\n-- Error Tests --\n");
    day_of_year(2024, 13, 10); // invalid month
    day_of_year(2024, 2, 30);  // invalid day
    month_day(2024, 400, &m, &d); // invalid yearday

    return 0;
}
