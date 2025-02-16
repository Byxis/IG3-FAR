#include "Library.h"
#include <stdio.h>
#include <stdlib.h>

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