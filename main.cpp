#include <chrono>
#include <iostream>
#include <thread>

#include "Cafe.h"
// #include "UnitTest.h"

using namespace std;

int main() {
  int customers;
  cout << "How many customers do you want?" << endl;
  cin >> customers;
  while (customers>10 || customers<1){
    cout << "Must be between 1 and 10! Try again: " << endl;
    cin >> customers;
  }

  Cafe cafe = Cafe(customers, 500, "cafe game");
  cafe.run();

  // cafe.viewPerformance();

  // cafe.get_cleaner().doTask(/*pointer to customer*/);
  // screen class- where you click will give a different thing i.e. click on a customer to get a customer


  // UnitTest unitTest;
  // unitTest.runTests();

  return 0;
}