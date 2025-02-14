#ifndef BOOK_H
#define BOOK_H

typedef struct BookStruct {
    char* isbn;
    char* title;
    char* author;
    int year;
} Book;

void printBook(const Book *book);
Book* createBook(char* isbn, char* title, char* author, int year);
Book* modifyBook(Book* bookToModify, char* isbn, char* title, char* author, int year);

#endif