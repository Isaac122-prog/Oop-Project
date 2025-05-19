#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

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
        sf::RenderWindow* win;    

        int runTime;
        
        int maxCustomers;
        Customer* customers;
        int numActiveCustomers;
        int activeCustomer;

        // bool food;
        // bool drink;
        Table* tables;

        Player player;
        Waiter waiter;
        Cleaner cleaner;
        Chef chef;
        Barista barista;
    public:
        sf::Clock startTime; // CHECK WHERE THIS SHOULD BE

        Cafe();
        Cafe(int max, int size, std::string title);

        void drawFrame();
        void run();
        void keyBindings();

        int get_maxCustomers();
        int get_gameDuration(); 
        
        void newCustomer(); // introduces the next customer based on the previous customer's stats
        void customerLeaves();  // customer leaves based on their stats
    
        void viewPerformance(); 

        Customer get_customer(int customerNumber);
        Table get_table(int tableNo);
        Player get_player();
        Cleaner get_cleaner();
        Waiter get_waiter();
        Chef get_chef();
        Barista get_barista();

        ~Cafe();
    
};

#endif