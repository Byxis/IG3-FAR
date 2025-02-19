#include "Date.h"
#include <stdlib.h>
#include <stdio.h>

Date* initialize_date(int day, int month, int year)
{
    Date* date = malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    date->isValid = true;
    return date;
}

void invalidateDate(Date* date)
{
    date->isValid = false;
}

bool isDateValid(Date* date)
{
    return date->isValid;
}

char* DatetoString(Date* date)
{
    char* result = (char*)malloc(11 * sizeof(char));    

    sprintf(result, "%02d/%02d/%04d", date->day, date->month, date->year);

    return result;
}

void addDaysToDate(Date* date, int days)
{
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((date->year % 4 == 0 && date->year % 100 != 0) || (date->year % 400 == 0))
    {
        daysInMonth[1] = 29;
    }

    date->day += days;

    while (date->day > daysInMonth[date->month - 1])
    {
        date->day -= daysInMonth[date->month - 1];
        date->month++;

        if (date->month > 12)
        {
            date->month = 1;
            date->year++;

            if ((date->year % 4 == 0 && date->year % 100 != 0) || (date->year % 400 == 0))
            {
                daysInMonth[1] = 29;
            }
            else
            {
                daysInMonth[1] = 28;
            }
        }
    }
}

int compareDate(Date* date1, Date* date2)
{
    if (date1->year < date2->year 
        || (date1->year == date2->year && date1->month < date2->month) 
        || (date1->year == date2->year && date1->month == date2->month && date1->day < date2->day))
        return -1;
    if (date1->year == date2->year && date1->month == date2->month && date1->day == date2->day)
        return 0;
    return 1;
}