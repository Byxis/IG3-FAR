#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Customer.h"
#include "Borrow.h"

typedef struct BookNodeStruct {
    Book* book;
    struct BookNodeStruct* prev;
    struct BookNodeStruct* next;
} BNode;

typedef struct BorrowNodeStruct {
    Borrow* borrow;
    struct BorrowNodeStruct* prev;
    struct BorrowNodeStruct* next;
} BoNode;

typedef struct CNodeStruct {
    Customer* customer;
    struct CNodeStruct* prev;
    struct CNodeStruct* next;
} CNode;

typedef struct LibraryStruct {
    BNode* rootBook;
    CNode* rootCustomer;
    BoNode* rootBorrow;
} Library;

//Constructor
Library* createLib();

//Books handler
void addBookToLib(Library* library, Book* book);
Book* getBookFromLib(Library* library, char* isbn);
void displayAllBooksInLib(Library* library);
void modifyBookFromLib(Library* library, char* isbn, char* title, char* author, int year);
void removeBookFromLib(Library* library, char* isbn);
void displayBook(Library* library, char* isbn);

//Customers handler
void addCustomerToLib(Library* library, Customer* customer);
Customer* getCustomerFromLib(Library* library, int id);
void displayAllCustomersInLib(Library* library);
void modifyCustomerFromLib(Library* library, int id, char* name, char* address);
void removeCustomerFromLib(Library* library, int id);
void displayCustomer(Library* library, int id);

//Borrow handler
void addBorrowToLib(Library* library, char* bookIsbn, int customerId, Date* borrowDate);
Borrow* getBorrowInLib(Library* library, char* bookIsbn, int customerId);
void displayAllBorrowsFromLib(Library* library);
void modifyBorrowFromLib(Library* library, char* bookIsbn, int customerId, char* newBookIsb, int newCustomerId, Date* borrowDate);
void modifyBorrowPreciseFromLib(Library* library, char* bookIsbn, int customerId, char* newBookIsb, int newCustomerId, Date* borrowDate, Date* returnDate);
void removeBorrowFromLib(Library* library, char* bookIsbn, int customerId);
void returnBookFromLib(Library* library, char* bookIsbn, int customerId, Date* returnDate);


#endif