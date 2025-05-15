#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Table.h"

#include <chrono>

class Customer{
    protected:
        int hunger;
        int disgust;
        int thirst;
        int happiness;
        bool isActive;

        Table* tableNo;
        // use SFML clock sf::Clock clock
        // sf::Time limit = sf::seconds(120);
        std::chrono::steady_clock::time_point startTime;
    public:
        Customer(Table* tableNo);

        void set_isActive(bool state);
        bool get_isActive();

        void increase_hunger();
        void decrease_hunger();
        int get_hunger();

        void increase_thirst();
        void decrease_thirst();
        int get_thirst();

        void increase_disgust();
        void decrease_disgust();
        int get_disgust();

        void set_tableNo(Table* tableNo);
        Table* get_tableNo();


        int get_happiness();
};

#endif