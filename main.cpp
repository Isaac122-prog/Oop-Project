#include <chrono>
#include <iostream>
#include <thread>

#include "Cafe.h"
#include "Customer.h"
#include "Player.h"
#include "Table.h"
#include "UnitTest.h"

using namespace std;

int main() {
  int customers;
  cout << "How many customers do you want?" << endl;
  cin >> customers;

  Cafe cafe = Cafe(3);

  // cout << gameCafe.get_maxCustomers() << endl;

  cafe.viewPerformance();

  // for (int i = 0; i < gameCafe.get_maxCustomers(); i++) {
  //   cout << "customer " << i << " score: " << gameCafe.get_customer(i).get_happiness()
  //        << endl;
  // }

  // UnitTest unitTest;
  // unitTest.runTests();

  return 0;
}