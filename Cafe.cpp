#include "Cafe.h"
#include "Customer.h"

#include <iostream>
#include <chrono>

using namespace std;


Cafe::Cafe(int maxCustomers){ 
    this->maxCustomers = maxCustomers;
    // maximum game duration will be 2 minutes for every customer
    gameDuration = chrono::seconds(maxCustomers*120);
    customers = new Customer[maxCustomers];

    // assigning customers to the pointer array
    for (int i=0; i<maxCustomers; i++){
        customers[i] = Customer();
    }

    // releasing the first customer
    customers[0].set_isActive(true);
}

void Cafe::set_maxCustomers(int max){
    maxCustomers = max;
}

int Cafe::get_maxCustomers(){
    return maxCustomers;
}

// I DON'T THINK WE NEED THIS
void Cafe::set_gameDuration(){
    // maximum game duration will be 2 minutes for every customer
    gameDuration = chrono::seconds(maxCustomers*120); 
}

chrono::seconds Cafe::get_gameDuration(){
    return gameDuration;
}

// returns the customer you want the attributes of
Customer Cafe::get_customer(int customerNumber){
    return customers[customerNumber];
}

// introduces the next customer based on the previous customer's stats -> not sure if this should be in the class or not
void Cafe::newCustomer(){
    for (int i=1; i<maxCustomers; i++){
        if (customers[i].get_isActive() == false && customers[i-1].get)
    }
}
//void CustomerLeaves();