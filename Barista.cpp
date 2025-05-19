#include "Barista.h"
#include "KitchenStaff.h"
#include "Employee.h"
#include "Customer.h"

#include <iostream>
#include <chrono>

using namespace std;

Barista::Barista():KitchenStaff(){}

void Barista::doTask(Customer* customerNo){
    // the barista's task is to make the drinks
    
    // check barista is not busy
    if (isBusy = true){
        cout << "chef is busy!" << endl;
    } else {

    // wait for 15 seconds -> FROM CHAT GPT
    auto startTime = chrono::steady_clock::now();
    auto duration = chrono::seconds(15);

    // set barista to busy during 15 second wait period
    while (chrono::steady_clock::now()-startTime < duration){
        isBusy = true;
    }

    // finished brewing!
    numDrink ++;

    isBusy = false;
    }
}

Barista::~Barista(){
}