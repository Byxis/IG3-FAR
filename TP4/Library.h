#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"

typedef struct NodeStruct {
    Book* book;
    struct NodeStruct* prev;
    struct NodeStruct* next;
} Node;


typedef struct LibraryStruct {
    Node* root;
    Node* curr;
} Library;

Library* createLib();
void addToBookLib(Library* library, Book* book);
Book* getBookFromLib(Library* library, char* isbn);
void displayAllBooksInLib(Library* library);
void modifyBookFromLib(Library* library, char* isbn, char* title, char* author, int year);
void removeBookFromLib(Library* library, char* isbn);

#endif