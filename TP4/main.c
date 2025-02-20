#include "Book.h"
#include "Library.h"
#include "Customer.h"
#include "Date.h"
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

    
    printf("-----     Test of Date Struct...     -----\n\n");
    Date* d1 = initialize_date(10, 3, 2024);
    Date* d2 = initialize_date(25, 1, 2025);
    Date* d3 = initialize_date(25, 1, 2025);
    setValid(d2, 0);
    printf("Date 1: %s\n", DatetoString(d1));
    printf("Date 2: %s\n", DatetoString(d2));
    printf("Date 3: %s\n", DatetoString(d3));
    printf("Date 1 is %s\n", isDateValid(d1) ? "valid" : "invalid");
    printf("Date 2 is %s\n", isDateValid(d2) ? "valid" : "invalid");
    printf("Date 1 is %s to Date 2\n", compareDate(d1,d2) == 0 ? "equal" : compareDate(d1, d2) < 0 ? "prior" : "posterior");
    printf("Date 2 is %s to Date 3\n", compareDate(d2,d3) == 0 ? "equal" : compareDate(d2, d3) < 0 ? "prior" : "posterior");
    printf("\n");

    addDaysToDate(d1, 127);
    printf("Date 1 + 127 days: %s\n", DatetoString(d1));
    printf("Date 1 is %s to Date 2\n", compareDate(d1,d2) == 0 ? "equal" : compareDate(d1, d2) < 0 ? "prior" : "posterior");
    printf("----- End of Test of Date Struct... -----\n\n\n\n");

    printf("-----     Test of Borrow Struct...     -----\n\n");
    Borrow* bo1 = createBorrow(b1->isbn, c1->id, d1);
    Borrow* bo2 = createBorrow(b2->isbn, c2->id, d2);
    printBorrow(bo1);
    printBorrow(bo2);
    printf("\n");

    modifyBorrow(bo1, b1->isbn, c1->id, d1);
    printBorrow(bo1);
    printf("\n");

    printf("----- End of Test of Borrow Struct... -----\n\n\n\n");

    printf("-----     Test of Library Borrow Struct...     -----\n\n");
    d1 = initialize_date(10, 3, 2024);
    d2 = initialize_date(25, 1, 2025);
    d3 = initialize_date(25, 1, 2025);
    addBorrowToLib(library, b1->isbn, c1->id, d1);
    returnBookFromLib(library, b1->isbn, c1->id, initialize_date(13, 8, 2024));
    addBorrowToLib(library, b2->isbn, c2->id, d2);
    addBorrowToLib(library, b2->isbn, c1->id, d3);
    returnBookFromLib(library, b2->isbn, c1->id, initialize_date(28, 1, 2025));
    displayAllBorrowsFromLib(library);

    printf("\nShowing all borrows of a book:\n");
    displayBook(library, b2->isbn);

    printf("\nShowing all borrows of a customer:\n");
    displayCustomer(library, c1->id);

    printf("\nRemoving first borrow:\n");
    removeBorrowFromLib(library, b1->isbn, c1->id);
    displayAllBorrowsFromLib(library);

    printf("\nModifying last borrow:\n");
    modifyBorrowFromLib(library, b2->isbn, c2->id, b1->isbn, c2->id, d1);
    displayAllBorrowsFromLib(library);

    printf("----- End of Test of Library Borrow Struct... -----\n\n\n\n");
    return 0;
}