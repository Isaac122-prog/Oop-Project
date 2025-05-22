#ifndef CLEANER_H
#define CLEANER_H

#include "Customer.h"
#include "Employee.h"
#include "Table.h"

class Cleaner : public Employee {
 protected:
 public:
  Cleaner();
  void doTask(Customer* customer) override;
  ~Cleaner();
};

#endif