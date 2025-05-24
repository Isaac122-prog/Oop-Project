#include "KitchenStaff.h"

#include <iostream>

#include "Cafe.h"
#include "Employee.h"

using namespace std;

// constructor
KitchenStaff::KitchenStaff() : Employee() {
  food = Consumable();
  drink = Consumable();
}

// HELPPPPPPP
void KitchenStaff::doTask(Customer* customer) {
  std::cout << "HELP I NEED TO FIX THIS" << std::endl;
}

// getters and setters
Consumable KitchenStaff::get_food() { return food; }
Consumable KitchenStaff::get_drink() { return drink; }

// destructor
KitchenStaff::~KitchenStaff(){}
