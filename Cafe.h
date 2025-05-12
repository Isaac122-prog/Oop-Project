#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <chrono>

#include "Customer.h"
#include "Table.h"

using namespace std;

class Cafe {
    protected:
        chrono::seconds gameDuration;
        int maxCustomers;
        Customer* customers;

        bool food;
        bool drink;
        Table* tables;
    public:
        Cafe();
        Cafe(int maxCustomers);

        int get_maxCustomers();

        chrono::seconds get_gameDuration();

        // returns the customer you want the attributes of
        Customer get_customer(int customerNumber);

        // introduces the next customer based on the previous customer's stats -> not sure if this should be in the class or not
        void newCustomer();
        void CustomerLeaves();
        
        // not quite sure what class this should be in
        void viewPerformance();
    
};

#endif