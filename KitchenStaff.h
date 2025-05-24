#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#include "Consumable.h"
#include "Employee.h"

using namespace std;

class Cafe;  // FORWARD DECLARATION OF CAFE TO AVOID CIRCLE OF PAIN

class KitchenStaff : public Employee {
 protected:
  Consumable food;
  Consumable drink;

 public:
  // constructor
  KitchenStaff();
  
  // getters
  Consumable get_food();
  Consumable get_drink();

  // destructor
  ~KitchenStaff();
};
#endif