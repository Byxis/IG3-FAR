#include "Book.h"
#include "Library.h"
#include <stdio.h>

int main()
{
    Book* def = createBook("ISBN", "TITLE", "AUTHOR", 1900);
    Book* b1 = createBook("978-0451524935", "1984", "George Orwell", 1984);
    Book* b2 = createBook("978-0553293357", "Foundation", "Isaac Asimov ", 1951);
    Book* b3 = createBook("978-1451673319", "Fahrenheit 451", "Ray Bradbury", 1953);
    printBook(def);
    printBook(b1);
    printBook(b2);
    printBook(b3);
    printf("\n-2\n");
    b1 = modifyBook(b1, "978-0451524935", "1984", "George Orwell", 1994);
    printf("\n-1\n");
    printBook(def);
    printf("\n0\n");
    printBook(b1);

    printf("\n1\n");
    Library* library = createLib();
    printf("\n2\n");
    addToBookLib(library, b1);
    printf("\n3\n");
    addToBookLib(library, b2);
    printf("\n4\n");
    addToBookLib(library, b3);
    printf("\n5\n");
    displayAllBooksInLib(library);
    printf("\n6\n");

    removeBookFromLib(library, b3->isbn);
    printf("\n7\n");
    displayAllBooksInLib(library);
    printf("\n8\n");

    modifyBookFromLib(library, b1->isbn, b1->title, b1->author, 1949);
    printf("\n9\n");
    displayAllBooksInLib(library);
    printf("\n10\n");

    return 0;
}