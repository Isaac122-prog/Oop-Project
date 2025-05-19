#ifndef BARISTA_H
#define BARISTA_H

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"

class Cafe;

class Barista : public KitchenStaff {
 protected:
 public:
  Barista();
  void doTask(Customer* customer, Cafe* cafe);
  ~Barista();
};

#endif