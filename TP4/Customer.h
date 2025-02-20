#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct CustomerStruct {
    int id;
    char* name;
    char* address;
} Customer;

void printCustomer(const Customer *customer);
Customer* createCustomer(int customerID, char* name, char* address);
Customer* modifyCustomer(Customer* customerToModify, int customerID, char* name, char* address);

#endif