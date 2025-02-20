#include "Book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBook(const Book *book)
{
    if (book == NULL) {
        printf("Erreur : Le livre est NULL.\n");
        return;
    }

    printf("%s - %s : %s (%d)\n", 
        book->isbn, book->title, book->author, book->year
    );
}

Book* createBook(char* isbn, char* title, char* author, int year)
{
    Book* book = (Book*) malloc(sizeof(Book));
    book->isbn = (char*) malloc(sizeof(char) * strlen(isbn) + 1);
    book->title = (char*) malloc(sizeof(char) * strlen(title) + 1);
    book->author = (char*) malloc(sizeof(char) * strlen(author) + 1);
    book->year = year;
    book->isAvailable = 1;
    strcpy(book->isbn, isbn);
    strcpy(book->title, title);
    strcpy(book->author, author);
    return book;
}

Book* modifyBook(Book* bookToModify, char* isbn, char* title, char* author, int year)
{
     if (bookToModify == NULL) {
        return NULL;
    }
    strcpy(bookToModify->isbn, isbn);
    strcpy(bookToModify->title, title);
    strcpy(bookToModify->author, author);
    bookToModify->year = year;
    return bookToModify;
}

Book* setAvailable(Book* book, int available)
{
    book->isAvailable = available;
}