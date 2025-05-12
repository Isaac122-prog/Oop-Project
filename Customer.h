#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    protected:
        int hunger;
        int disgust;
        int thirst;
        int happiness;
        bool isActive;

        // use SFML clock sf::Clock clock
        // sf::Time limit = sf::seconds(120);
    public:
        Customer();

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

        int get_happiness();
};

#endif