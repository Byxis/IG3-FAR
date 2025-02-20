#ifndef BORROW_H
#define BORROW_H
#include "Date.h"

typedef struct BorrowStruct {
    char* bookIsbn;
    int customerId;
    Date* date;
    Date* returnDate;
} Borrow;

Borrow* createBorrow(char* bookIsbn, int customerId, Date* borrowDate);
void modifyBorrow(Borrow* borrow, char* bookIsbn, int customerId, Date* borrowDate);
void modifyBorrowPrecise(Borrow* borrow, char* bookIsbn, int customerId, Date* borrowDate, Date* returnDate);
void printBorrow(const Borrow* borrow);
void returnBook(Borrow* borrow, Date* returnDate);

#endif