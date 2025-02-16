#include "Book.h"
#include "Library.h"
#include "Customer.h"
#include <stdio.h>

int main()
{
    printf("-----     Test of Book Struct...     -----\n\n");
    Book* b1 = createBook("978-0451524935", "1984", "George Orwell", 1984);
    Book* b2 = createBook("978-0553293357", "Foundation", "Isaac Asimov ", 1951);
    Book* b3 = createBook("978-1451673319", "Fahrenheit 451", "Ray Bradbury", 1953);
    printBook(b1);
    printBook(b2);
    printBook(b3);
    printf("\n\nModifying of the first book:\n");

    b1 = modifyBook(b1, "978-0451524935", "1984", "George Orwell", 1994);
    printBook(b1);
    printf("\n");


    printf("----- End of Test of Book Struct... -----\n\n\n\n");

    printf("-----     Test of Library Book Struct...     -----\n\n");
    Library* library = createLib();
    addBookToLib(library, b1);
    addBookToLib(library, b2);
    addBookToLib(library, b3);
    displayAllBooksInLib(library);
    printf("\n");

    printf("\nRemoving first book\n");
    removeBookFromLib(library, b3->isbn);
    displayAllBooksInLib(library);
    printf("\n");

    printf("\nModifying last book\n");
    modifyBookFromLib(library, b1->isbn, b1->title, b1->author, 1949);
    displayAllBooksInLib(library);
    printf("\n");

    printf("----- End of Test of Library Book Struct... -----\n\n\n\n");

    printf("-----     Test of Customer Struct...     -----\n\n");
    Customer* c1 = createCustomer(1, "Alice Dupont", "123 Rue de la Liberté");
    Customer* c2 = createCustomer(2, "Bob Martin"," 456 Avenue de la République");
    Customer* c3 = createCustomer(3, "Charlie Vincent", "789 Boulevard des Etoiles");
    printCustomer(c1);
    printCustomer(c2);
    printCustomer(c3);
    printf("\n");  

    modifyCustomer(c1, 1, "Alice Dupont", "987 Rue de la Paix");
    printCustomer(c1);
    printCustomer(c2);
    printCustomer(c3);
    printf("\n");

    printf("----- End of Test of Book Struct... -----\n\n\n\n");

    printf("-----     Test of Library Customer Struct...     -----\n\n");

    addCustomerToLib(library, c1);
    addCustomerToLib(library, c2);
    addCustomerToLib(library, c3);
    displayAllCustomersInLib(library);
    printf("\n");

    printf("\nRemoving first customer:\n");
    removeCustomerFromLib(library, c3->id);
    displayAllCustomersInLib(library);
    printf("\n");

    printf("\nModifying last customer:\n");
    modifyCustomerFromLib(library, c1->id, c1->name, "12 Rue de la Paix");
    displayAllCustomersInLib(library);
    printf("\n");

    printf("----- End of Test of Library Customer Struct... -----\n\n\n\n");
    return 0;
}