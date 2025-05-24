#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Consumable.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

class Cafe;

class Chef : public KitchenStaff {
 protected:
 public:
  // constructor
  Chef();
  // doTask: sets the chef to busy and sets their timer for cooking the food
  void doTask(Customer* customer, Cafe* cafe);
  // destructor
  ~Chef();
};

#endif