#include "Library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Library* createLib()
{
    Library* library = (Library*) malloc(sizeof(Library));
    if (library == NULL) {
        return NULL;
    }

    library->rootBook = NULL;
    library->rootCustomer = NULL;

    return library;
}

//---------------------------------------------------------------------------------------
//                                                                                       
//                                     BOOKS                                            
//                                                                                       
//---------------------------------------------------------------------------------------

void addBookToLib(Library* library, Book* book)
{
    BNode* newNode = (BNode*) malloc(sizeof(BNode));
    BNode* rootNode = library->rootBook;
    newNode->book = book;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (rootNode != NULL)
    {
        newNode->next = rootNode;
        rootNode->prev = newNode;
    }
    library->rootBook = newNode;

}

Book* getBookFromLib(Library* library, char* isbn)
{
    BNode* node = library->rootBook;

    while (node->next != NULL && node->book->isbn != isbn)
    {
        node = node->next;
    }
    if (node != NULL && node->book->isbn == isbn)
    {
        return node->book;
    }
    return NULL;
}

void displayAllBooksInLib(Library* library)
{
    BNode* node = library->rootBook;
    while (node != NULL)
    {
        printBook(node->book);
        node = node->next;
    }
}

void modifyBookFromLib(Library* library, char* isbn, char* title, char* author, int year)
{
    Book* libBook = getBookFromLib(library, isbn);
    if (libBook != NULL)
    {
        modifyBook(libBook, isbn, title, author, year);
    }
}

void removeBookFromLib(Library* library, char* isbn)
{
    BNode* node = library->rootBook;
    if(node == NULL)
    {
        return;
    }

    while (node->next != NULL && node->book->isbn != isbn)
    {
        node = node->next;
    }

    if (node != NULL && node->book->isbn == isbn)
    {
        BNode* prev = node->prev;
        BNode* next = node->next;
        if(prev == NULL)
        {
            library->rootBook = next;
        }
        if(next != NULL)
        {
            next->prev = prev;
        }
        if(prev != NULL)
        {
            prev->next = next;
        }

        free(node);
    }
}

void displayBook(Library* library, char* isbn)
{
    Book* book = getBookFromLib(library, isbn);
    if (book != NULL && book->isbn == isbn)
    {
        printBook(book);
        BoNode* nodeBorrow = library->rootBorrow;
        while (nodeBorrow != NULL)
        {
            if (!strcmp(nodeBorrow->borrow->bookIsbn, isbn))
            {
                printBorrow(nodeBorrow->borrow);
            }
            nodeBorrow = nodeBorrow->next;
        }
    }
}

//---------------------------------------------------------------------------------------
//                                                                                       
//                                     CUSTOMERS                                            
//                                                                                       
//---------------------------------------------------------------------------------------

void addCustomerToLib(Library* library, Customer* customer)
{
    CNode* newNode = (CNode*) malloc(sizeof(CNode));
    CNode* rootNode = library->rootCustomer;
    newNode->customer = customer;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (rootNode != NULL)
    {
        newNode->next = rootNode;
        rootNode->prev = newNode;
    }
    library->rootCustomer = newNode;

}

Customer* getCustomerFromLib(Library* library, int id)
{
    CNode* node = library->rootCustomer;

    while (node->next != NULL && node->customer->id != id)
    {
        node = node->next;
    }
    if (node != NULL && node->customer->id == id)
    {
        return node->customer;
    }
    return NULL;
}

void displayAllCustomersInLib(Library* library)
{
    CNode* node = library->rootCustomer;
    while (node != NULL)
    {
        printCustomer(node->customer);
        node = node->next;
    }
}

void modifyCustomerFromLib(Library* library, int id, char* name, char* address)
{
    Customer* libBook = getCustomerFromLib(library, id);
    if (libBook != NULL)
    {
        modifyCustomer(libBook, id, name, address);
    }
}

void removeCustomerFromLib(Library* library, int id)
{
    CNode* node = library->rootCustomer;
    if(node == NULL)
    {
        return;
    }

    while (node->next != NULL && node->customer->id != id)
    {
        node = node->next;
    }

    if (node != NULL && node->customer->id == id)
    {
        CNode* prev = node->prev;
        CNode* next = node->next;
        if(prev == NULL)
        {
            library->rootCustomer = next;
        }
        if(next != NULL)
        {
            next->prev = prev;
        }
        if(prev != NULL)
        {
            prev->next = next;
        }

        free(node);
    }
}

void displayCustomer(Library* library, int id)
{
    CNode* node = library->rootCustomer;
    while (node != NULL && node->customer->id != id)
    {
        node = node->next;
    }
    if (node != NULL && node->customer->id == id)
    {
        printCustomer(node->customer);
        BoNode* nodeBorrow = library->rootBorrow;
        while (nodeBorrow != NULL)
        {
            if (nodeBorrow->borrow->customerId == id)
            {
                printBorrow(nodeBorrow->borrow);
            }
            nodeBorrow = nodeBorrow->next;
        }
    }
}

//---------------------------------------------------------------------------------------
//                                                                                       
//                                     BORROW                                            
//      
//---------------------------------------------------------------------------------------

void addBorrowToLib(Library* library, char* bookIsbn, int customerId, Date* borrowDate)
{
    BoNode* newNode = (BoNode*) malloc(sizeof(BoNode));
    BoNode* rootNode = library->rootBorrow;
    newNode->borrow = createBorrow(bookIsbn, customerId, borrowDate);
    newNode->prev = NULL;
    newNode->next = NULL;
    if (rootNode != NULL)
    {
        newNode->next = rootNode;
        rootNode->prev = newNode;
    }
    library->rootBorrow = newNode;
}


Borrow* getBorrowInLib(Library* library, char* bookIsbn, int customerId)
{
    BoNode* node = library->rootBorrow;

    while (node->next != NULL && !(!strcmp(node->borrow->bookIsbn, bookIsbn) && node->borrow->customerId == customerId))
    {
        node = node->next;
    }
    if (node != NULL && !strcmp(node->borrow->bookIsbn, bookIsbn) && node->borrow->customerId == customerId)
    {
        return node->borrow;
    }
    return NULL;
}

void displayAllBorrowsFromLib(Library* library)
{
    BoNode* node = library->rootBorrow;
    while (node != NULL)
    {
        printBorrow(node->borrow);
        node = node->next;
    }
}

void modifyBorrowFromLib(Library* library, char* bookIsbn, int customerId, char* newBookIsb, int newCustomerId, Date* borrowDate)
{
    Borrow* borrow = getBorrowInLib(library, bookIsbn, customerId);
    if (borrow != NULL)
    {
        modifyBorrow(borrow, newBookIsb, newCustomerId, borrowDate);
    }
}

void modifyBorrowPreciseFromLib(Library* library, char* bookIsbn, int customerId, char* newBookIsb, int newCustomerId, Date* borrowDate, Date* returnDate)
{
    Borrow* borrow = getBorrowInLib(library, bookIsbn, customerId);
    if (borrow != NULL)
    {
        modifyBorrowPrecise(borrow, newBookIsb, newCustomerId, borrowDate, returnDate);
    }
}

void removeBorrowFromLib(Library* library, char* bookIsbn, int customerId)
{
    BoNode* node = library->rootBorrow;
    if(node == NULL)
    {
        return;
    }

    while (node->next != NULL && (strcmp(node->borrow->bookIsbn, bookIsbn) || node->borrow->customerId != customerId))
    {
        node = node->next;
    }

    if (node != NULL && !strcmp(node->borrow->bookIsbn, bookIsbn) && node->borrow->customerId == customerId)
    {
        BoNode* prev = node->prev;
        BoNode* next = node->next;
        if(prev == NULL)
        {
            library->rootBorrow = next;
        }
        if(next != NULL)
        {
            next->prev = prev;
        }
        if(prev != NULL)
        {
            prev->next = next;
        }

        free(node);
    }
}


void returnBookFromLib(Library* library, char* bookIsbn, int customerId, Date* returnDate)
{
    Borrow* libBook = getBorrowInLib(library, bookIsbn, customerId);
    if (libBook != NULL)
    {
        returnBook(libBook, returnDate);
    }
}



void saveAllData(Library* library, char* booksFileName, char* customersFileName, char* borrowsFileName)
{
    FILE* booksFile = fopen(booksFileName, "w");
    BNode* bookNode = library->rootBook;
    while (bookNode != NULL) 
    {
        Book* b = bookNode->book;
        fprintf(booksFile, "%s ; %s ; %s ; %d ; %d \n", b->isbn, b->title, b->author, b->year, b->isAvailable);
        bookNode = bookNode->next;
    }
    fclose(booksFile);

    FILE* customersFile = fopen(customersFileName, "w");
    CNode* customerNode = library->rootCustomer;
    while (customerNode != NULL) 
    {
        Customer* c = customerNode->customer;
        fprintf(customersFile, "%d ; %s ; %s \n", c->id, c->name, c->address);
        customerNode = customerNode->next;
    }
    fclose(customersFile);
    
    FILE* borrowsFile = fopen(borrowsFileName, "w");
    BoNode* borrowNode = library->rootBorrow;
    while (borrowNode != NULL) 
    {
        Borrow* b = borrowNode->borrow;
        fprintf(borrowsFile, "%s ; %d ; %s ; %s \n", b->bookIsbn, b->customerId, DatetoString(b->date), DatetoString(b->returnDate));
        borrowNode = borrowNode->next;
    }
    fclose(borrowsFile);
}