#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Customer.h"

#include <chrono>

class Employee {
 protected:
  bool isBusy;       // whether an employee is busy or not
 public:
  Employee();  // default constructor

  virtual void doTask(Customer* customer) = 0;  // virtual function making this
                                                // an abstract class
};

#endif