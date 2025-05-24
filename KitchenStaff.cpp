#include "KitchenStaff.h"

#include <iostream>
#include "Employee.h"

using namespace std;

// constructor
KitchenStaff::KitchenStaff() : Employee() {
  food = Consumable();
  drink = Consumable();
}

// getters and setters
Consumable KitchenStaff::get_food() { return food; }
Consumable KitchenStaff::get_drink() { return drink; }

// destructor
KitchenStaff::~KitchenStaff(){}
