#include "KitchenStaff.h"
#include "Employee.h"
#include "Cafe.h"

#include <iostream>

using namespace std;

// default constructor
KitchenStaff::KitchenStaff() : Employee() {}

void KitchenStaff::doTask(Customer* customer) {
  std::cout << "HELP I NEED TO FIX THIS" << std::endl;
}
