#ifndef BARISTA_H
#define BARISTA_H

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"
#include "Consumable.h"

class Cafe;

class Barista : public KitchenStaff {
 private:
 public:
  Barista();
  void doTask(Customer* customer, Cafe* cafe);
  ~Barista();
};

#endif