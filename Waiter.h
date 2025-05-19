#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"
// #include "Food.h"
// #include "Drink.h"

class Cafe;

class Waiter : public KitchenStaff {
 protected:
 public:
  Waiter();

  void doTask(Customer* customer, Cafe* cafe);
};

#endif