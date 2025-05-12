#include <iostream>
#include <chrono>

#include "Cafe.h"
#include "Customer.h"

using namespace std;

int main(){

    int maxCustomers;
    cout << "How many customers do you want?" << endl;
    cin >> maxCustomers;
    
    Cafe gameCafe = Cafe(maxCustomers);

   
    return 0;
}