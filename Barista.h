#ifndef BARISTA_H
#define BARISTA_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Consumable.h"
#include "Customer.h"
#include "Employee.h"
#include "KitchenStaff.h"

class Cafe;

class Barista : public KitchenStaff {
 private:
 public:
  // constructor
  Barista();
  // doTask: sets the barista to busy and sets their timer for brewing the
  // drinks
  void doTask(Customer* customer, Cafe* cafe);
  // destructor
  ~Barista();
};

#endif