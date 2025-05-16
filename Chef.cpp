#include "Chef.h"
#include "KitchenStaff.h"
#include "Employee.h"
#include "Customer.h"

#include <iostream>
#include <chrono>

using namespace std;

Chef::Chef():KitchenStaff(){}
        
void Chef::doTask(Customer* customerNo){
    // the chef's task is to make the food servings
    
    // check chef is not busy
    if (isBusy = true){
        cout << "chef is busy!" << endl;
    } else {

    // wait for 15 seconds -> FROM CHAT GPT
    auto startTime = chrono::steady_clock::now();
    auto duration = chrono::seconds(15);

    // set chef to busy during 15 second wait period
    while (chrono::steady_clock::now()-startTime < duration){
        isBusy = true;
    }

    // finished cooking!
    numFood ++;

    isBusy = false;
    }

    
}