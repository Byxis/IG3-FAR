#include "Book.h"
#include "Library.h"
#include "Customer.h"
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
    printf("\n");

    b1 = modifyBook(b1, "978-0451524935", "1984", "George Orwell", 1994);
    printBook(def);
    printBook(b1);
    printf("\n");

    Library* library = createLib();
    addToBookLib(library, b1);
    addToBookLib(library, b2);
    addToBookLib(library, b3);
    displayAllBooksInLib(library);
    printf("\n");

    removeBookFromLib(library, b3->isbn);
    displayAllBooksInLib(library);
    printf("\n");

    modifyBookFromLib(library, b1->isbn, b1->title, b1->author, 1949);
    displayAllBooksInLib(library);
    printf("\n");


    return 0;
}