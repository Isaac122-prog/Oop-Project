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

// getters 
Consumable KitchenStaff::get_food() { return food; }
Consumable KitchenStaff::get_drink() { return drink; }

// destructor
KitchenStaff::~KitchenStaff(){}
