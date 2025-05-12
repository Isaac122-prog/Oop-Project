#include "Waiter.h"

#include <chrono>
#include <iostream>

#include "Employee.h"
#include "KitchenStaff.h"

using namespace std;

Waiter::Waiter() : KitchenStaff() {}

// waiter will be called using button 'call waiter for table 2 or smth'

void Waiter::doTask(int customerNumber) {
  // the waiter's task is to serve the food to the customer

  // check waiter is not busy
  if (isBusy = true) {
    cout << "waiter is busy!" << endl;
  } else {
    
    // TRICKY: waiter can only serve food/drink if they have been made
    if (numFood == 0 && numDrink == 0) {
      cout << "no food or drink to be served!" << endl;
    }
    if (numFood > 0) {
      // wait for 15 seconds -> FROM CHAT GPT
      auto startTime = chrono::steady_clock::now();
      auto duration = chrono::seconds(15);

      // set waiter to busy during 15 second wait period
      while (chrono::steady_clock::now() - startTime < duration) {
        isBusy = true;
      }

      // food is served!
      numFood --;

      // access the customer to use customer[i].increase_hunger();
    }

    if (numDrink > 0) {
        // wait for 15 seconds -> FROM CHAT GPT
        auto startTime = chrono::steady_clock::now();
        auto duration = chrono::seconds(15);
  
        // set waiter to busy during 15 second wait period
        while (chrono::steady_clock::now() - startTime < duration) {
          isBusy = true;
        }
  
        // drink is served!
        numDrink --;
        // access the customer to use customer[i].increase_thirst();
      }

    isBusy = false;
  }
}

