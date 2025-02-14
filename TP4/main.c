#include "Book.h"
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
    b1 = modifyBook(b1, "978-0451524935", "1984", "George Orwell", 1949);
    printBook(def);
    printBook(b1);
    return 0;
}