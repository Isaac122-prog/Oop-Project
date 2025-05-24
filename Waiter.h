#ifndef WAITER_H
#define WAITER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Customer.h"
#include "Employee.h"

class Cafe;

class Waiter : public Employee {
 protected:
 public:
  // constructor
  Waiter();
  // doTask: sets the waiter to busy and sets their timer for serving the
  // consumables
  void doTask(Customer* customer, Cafe* cafe);
  // destructor
  ~Waiter();
};

#endif