#ifndef DATE_H
#define DATE_H
#include <stdbool.h>

typedef struct DateStruct {
    int day;
    int month;
    int year;
    bool isValid;
} Date;

Date* initialize_date(int day, int month, int year);
void invalidateDate(Date* date);
bool isDateValid(Date* date);
char* DatetoString(Date* date);
void addDaysToDate(Date* date, int days);
int compareDate(Date* date1, Date* date2);

#endif