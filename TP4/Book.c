#include "Book.h"
#include <stdio.h>
#include <stdlib.h>

void printBook(const Book *book)
{
    printf("%s - %s : %s (%d)\n", 
        book->isbn, book->title, book->author, book->year
    );
}

Book* createBook(char* isbn, char* title, char* author, int year)
{
    Book* book = (Book*)malloc(sizeof(Book));
    book->isbn = isbn;
    book->title = title;
    book->author = author;
    book->year = year;
    return book;
}

Book* modifyBook(Book* bookToModify, char* isbn, char* title, char* author, int year)
{
    bookToModify->isbn = isbn;
    bookToModify->title = title;
    bookToModify->author = author;
    bookToModify->year = year;
    return bookToModify;
}