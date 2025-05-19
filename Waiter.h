#ifndef CLEANER_H
#define CLEARNER_H

#include "Employee.h"
#include "KitchenStaff.h"
#include "Customer.h"

class Waiter : public KitchenStaff {
 protected:
 public:
  Waiter();

  void doTask(Customer* customer);
};

#endif