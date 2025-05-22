#ifndef WAITER_H
#define WAITER_H

#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"
// #include "Food.h"
// #include "Drink.h"

class Cafe;

class Waiter : public KitchenStaff {
 protected:
 public:
  Waiter();
  void doTask(Customer* customer, Cafe* cafe);
  ~Waiter();
};

#endif