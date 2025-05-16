#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <chrono>

#include "Customer.h"
#include "Table.h"

#include "Player.h"
#include "Employee.h"
#include "KitchenStaff.h"
#include "Waiter.h"
#include "Cleaner.h"
#include "Chef.h"
#include "Barista.h"

using namespace std;

class Cafe {
    protected:
        chrono::seconds gameDuration;
        int maxCustomers;
        Customer* customers;
        int numActiveCustomers;

        // bool food;
        // bool drink;
        Table* tables;

        Player player;
        Waiter waiter;
        Cleaner cleaner;
        Chef chef;
        Barista barista;
    public:
        Cafe();
        Cafe(int max);

        int get_maxCustomers();

        chrono::seconds get_gameDuration();

        // returns the customer you want the attributes of
        Customer get_customer(int customerNumber);

        // introduces the next customer based on the previous customer's stats
        void newCustomer();
        // customer leaves based on their stats
        void CustomerLeaves();
        
        // not quite sure what class this should be in
        void viewPerformance();

        Table get_table(int tableNo);
        Customer get_customer(int customerNo);

        Player get_player();

        Cleaner get_cleaner();
        Waiter get_waiter();
        Chef get_chef();
        Barista get_barista();
    
};

#endif