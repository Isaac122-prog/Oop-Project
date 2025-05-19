#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"

class Cafe;

class Chef : public KitchenStaff {
 protected:
 public:
  Chef();

  void doTask(Customer* customer, Cafe* cafe);
};

#endif