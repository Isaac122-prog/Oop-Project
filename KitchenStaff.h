#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

#include "Employee.h"

using namespace std;

class KitchenStaff : public Employee {
 protected:
  int numFood;
  int numDrink;

 public:
  KitchenStaff();  // default constructor
  void doTask(int customerNumber);
};

#endif