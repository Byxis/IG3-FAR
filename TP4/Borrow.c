#include "Borrow.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Borrow* createBorrow(char* bookIsbn, int customerId, Date* borrowDate)
{
    Borrow* borrow = (Borrow*) malloc(sizeof(Borrow));
    borrow->bookIsbn = (char*) malloc(sizeof(char) * strlen(bookIsbn) + 1);
    
    strcpy(borrow->bookIsbn, bookIsbn);
    borrow->customerId = customerId;
    borrow->date = borrowDate;
    Date* returnDate = initialize_date(borrowDate->day, borrowDate->month, borrowDate->year);
    addDaysToDate(returnDate, 60);
    setValid(returnDate, 0);
    borrow->returnDate = returnDate;
    return borrow;
}

void printBorrow(const Borrow* borrow)
{
    printf("Book ISBN: %s - ", borrow->bookIsbn);
    printf("Customer ID: %d - ", borrow->customerId);
    if (isDateValid(borrow->returnDate))
    {
        Date theoricalReturnDate = *borrow->date;
        addDaysToDate(&theoricalReturnDate, 60);
        if (compareDate(borrow->returnDate, &theoricalReturnDate) > 0)
        {
            printf("Borrow Date: %s until %s (late)\n", DatetoString(borrow->date), DatetoString(borrow->returnDate));
        }
        else
        {
            printf("Borrow Date: %s until %s\n", DatetoString(borrow->date), DatetoString(borrow->returnDate));
        }
    }
    else
    {
        printf("Borrow Date: %s until (not returned)\n", DatetoString(borrow->date));
    }
}


void modifyBorrow(Borrow* borrow, char* bookIsbn, int customerId, Date* borrowDate)
{
    strcpy(borrow->bookIsbn, bookIsbn);
    borrow->customerId = customerId;
    borrow->date = borrowDate;
    Date* returnDate = initialize_date(borrowDate->day, borrowDate->month, borrowDate->year);
    addDaysToDate(returnDate, 60);
    setValid(returnDate, 0);
    borrow->returnDate = returnDate;
}

void modifyBorrowPrecise(Borrow* borrow, char* bookIsbn, int customerId, Date* borrowDate, Date* returnDate)
{
    strcpy(borrow->bookIsbn, bookIsbn);
    borrow->customerId = customerId;
    borrow->date = borrowDate;
    setValid(returnDate, 0);
    borrow->returnDate = returnDate;
}

void returnBook(Borrow* borrow, Date* returnDate)
{
    setValid(returnDate, 1);
    borrow->returnDate = returnDate;
}