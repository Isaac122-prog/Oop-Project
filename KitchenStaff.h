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

  void doTask(Customer* customer)
      override;  // NEED TO OVERRIDE THIS FOR ERRORS I NEED HELP
  virtual void doTask(Customer* customer,
                      Cafe* cafe) = 0;  // WANT THIS TO OVERRIDE EMPLOYEE CLASS
  
  // getters
  Consumable get_food();
  Consumable get_drink();

  // destructor
  ~KitchenStaff();
};
#endif