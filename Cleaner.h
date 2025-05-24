#ifndef CLEANER_H
#define CLEANER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Customer.h"
#include "Employee.h"
#include "Table.h"

class Cafe;

class Cleaner : public Employee {
 protected:
 public:
  // constructor
  Cleaner();
  // doTask: sets the cleaner to busy and sets their timer for cleaning the
  // customer's table
  void doTask(Customer* customer, Cafe* cafe) override;
  // destructor
  ~Cleaner();
};

#endif