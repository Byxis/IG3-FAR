#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>

void printCustomer(const Customer *customer) 
{
    printf("ID: C%03d, Name: %s, Adress: %s\n", customer->id, customer->name, customer->address);
}

Customer* createCustomer(int customerID, char* name, char* address) 
{
    Customer* customer = malloc(sizeof(Customer));
    customer->id = customerID;
    customer->name = name;
    customer->address = address;
    return customer;
}

Customer* modifyCustomer(Customer* customerToModify, int customerID, char* name, char* address) 
{
    customerToModify->id = customerID;
    customerToModify->name = name;
    customerToModify->address = address;
    return customerToModify;
}