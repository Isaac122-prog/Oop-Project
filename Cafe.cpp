#include "Cafe.h"
#include "Customer.h"

#include <iostream>
#include <chrono>

using namespace std;

Cafe::Cafe(){
    maxCustomers = 0;
    customers = new Customer[maxCustomers];
    tables = new Table[maxCustomers];
}

Cafe::Cafe(int max){ 
    maxCustomers = max;
    // maximum game duration will be 2 minutes for every customer
    gameDuration = chrono::seconds(maxCustomers*120);
    customers = new Customer[maxCustomers];

    // assigning customers to the customer pointer array
    for (int i=0; i<maxCustomers; i++){
        customers[i] = Customer();
    }

    // releasing the first customer
    customers[0].set_isActive(true);

    // creating an array of tables
    tables = new Table[maxCustomers];

    // assigning tables to the table pointer array
    for (int j=0; j<maxCustomers; j++){
        tables[j] = Table();
    }
}

int Cafe::get_maxCustomers(){
    return maxCustomers;
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
        if (customers[i].get_isActive() == false && customers[i-1].get_isActive() == true){
            customers[i].set_isActive(true);
            break;
        }
    }
}

// customers will leave if they have a happiness of 15
void Cafe::CustomerLeaves(){
    for (int i=0; i<maxCustomers; i++){
        if (customers[i].get_isActive() == true && customers[i].get_happiness() == 15){
            customers[i].set_isActive(false);
        }
    }
}

void Cafe::viewPerformance(){
    cout << maxCustomers << endl;
    
    for (int i=0; i<maxCustomers; i++){
        cout << "customer " << i << " score: " << get_customer(i).get_happiness() << endl;
    }
}