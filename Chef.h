#ifndef CHEF_H
#define CHEF_H

#include <SFML/Graphics.hpp>

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"
#include "Consumable.h"

class Cafe;

class Chef : public KitchenStaff {
 protected:
 public:
  Chef();
  void doTask(Customer* customer, Cafe* cafe);
  ~Chef();
};

#endif