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
    borrow->returnDate = returnDate;
    return borrow;
}

void printBorrow(const Borrow* borrow)
{
    printf("Book ISBN: %s - ", borrow->bookIsbn);
    printf("Customer ID: %d - ", borrow->customerId);
    printf("Borrow Date: %s until %s\n", DatetoString(borrow->date), DatetoString(borrow->returnDate));
}


void modifyBorrow(Borrow* borrow, char* bookIsbn, int customerId, Date* borrowDate)
{
    strcpy(borrow->bookIsbn, bookIsbn);
    borrow->customerId = customerId;
    borrow->date = borrowDate;
    Date* returnDate = initialize_date(borrowDate->day, borrowDate->month, borrowDate->year);
    addDaysToDate(returnDate, 60);
    borrow->returnDate = returnDate;
}

void modifyBorrowPrecise(Borrow* borrow, char* bookIsbn, int customerId, Date* borrowDate, Date* returnDate)
{
    strcpy(borrow->bookIsbn, bookIsbn);
    borrow->customerId = customerId;
    borrow->date = borrowDate;
    borrow->returnDate = returnDate;
}