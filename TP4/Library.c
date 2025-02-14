#include "Library.h"
#include <stdio.h>
#include <stdlib.h>

Library* createLib()
{
    Library* library = (Library*) malloc(sizeof(Library));
    if (library == NULL) {
        return NULL;
    }

    library->root = NULL;
    library->curr = NULL;

    return library;
}

void addToBookLib(Library* library, Book* book)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* rootNode = library->root;
    newNode->book = book;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (rootNode != NULL)
    {
        newNode->next = rootNode;
        rootNode->prev = newNode;
    }
    library->root = newNode;

}

Book* getBookFromLib(Library* library, char* isbn)
{
    Node* node = library->root;

    while (node->next != NULL && node->book->isbn != isbn)
    {
        node = node->next;
    }
    if (node->book->isbn == isbn)
    {
        return node->book;
    }
    return NULL;
}

void displayAllBooksInLib(Library* library)
{
    Node* node = library->root;
    while (node != NULL)
    {
        printf("a");
        printBook(node->book);
        printf("b");
        node = node->next;
        printf("c");
    }
}

void modifyBookFromLib(Library* library, char* isbn, char* title, char* author, int year)
{
    Book* libBook = getBookFromLib(library, isbn);
    if (libBook->isbn == isbn)
    {
        modifyBook(libBook, isbn, title, author, year);
    }
}

void removeBookFromLib(Library* library, char* isbn)
{
    Node* node = library->root;

    while (node->next != NULL && node->book->isbn != isbn)
    {
        node = node->next;
    }

    if (node->book->isbn == isbn)
    {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;

        free(node);
    }
}