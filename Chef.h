#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"

class Chef : public KitchenStaff {
 protected:
 public:
  Chef();

  void doTask(Customer* customerNo);
};

#endif