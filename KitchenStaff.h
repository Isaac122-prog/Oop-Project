#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

#include "Employee.h"

using namespace std;

class Cafe; // FORWARD DECLARATION OF CAFE TO AVOID CIRCLE OF PAIN

class KitchenStaff : public Employee {
 protected:
  // int numFood;
  // int numDrink; MAJOR ISSUE THESE SHOULD BE PART OF CAFE

 public:
  KitchenStaff();  // default constructor
  void doTask(Customer* customer) override; // NEED TO OVERRIDE THIS FOR ERRORS I NEED HELP

  virtual void doTask(Customer* customer, Cafe* cafe) = 0;  // WANT THIS TO OVERRIDE EMPLOYEE CLASS
};
#endif