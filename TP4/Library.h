#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Customer.h"

typedef struct BNodeStruct {
    Book* book;
    struct BNodeStruct* prev;
    struct BNodeStruct* next;
} BNode;

typedef struct CNodeStruct {
    Customer* customer;
    struct CNodeStruct* prev;
    struct CNodeStruct* next;
} CNode;

typedef struct LibraryStruct {
    BNode* rootBook;
    CNode* rootCustomer;
} Library;

//Constructor
Library* createLib();

//Books handler
void addBookToLib(Library* library, Book* book);
Book* getBookFromLib(Library* library, char* isbn);
void displayAllBooksInLib(Library* library);
void modifyBookFromLib(Library* library, char* isbn, char* title, char* author, int year);
void removeBookFromLib(Library* library, char* isbn);

//Customers handler
void addCustomerToLib(Library* library, Customer* customer);
Customer* getCustomerFromLib(Library* library, int id);
void displayAllCustomersInLib(Library* library);
void modifyCustomerFromLib(Library* library, int id, char* name, char* address);
void removeCustomerFromLib(Library* library, int id);

#endif