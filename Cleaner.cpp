#include "Cleaner.h"
#include "Employee.h"
#include "Table.h"

#include <chrono>
#include <iostream>

using namespace std;

// default constructor
Cleaner::Cleaner():Employee(){}

void Cleaner::doTask(int customerNumber){
    // the cleaner's task is to clean this specific customer's table

    // check cleaner is not busy
    if (isBusy = true){
        cout << "cleaner is busy!" << endl;
    } else {

    // wait for 15 seconds -> FROM CHAT GPT
    auto startTime = chrono::steady_clock::now();
    auto duration = chrono::seconds(15);

    // set cleaner to busy during 15 second wait period
    while (chrono::steady_clock::now()-startTime < duration){
        isBusy = true;
    }

    // setting the isClean property from table class to true
    // tables[tableNo].set_isClean(true);

    // access the customer to use customer[i].increase_disgust();

    isBusy = false;
    }
}