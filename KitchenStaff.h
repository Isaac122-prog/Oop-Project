#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

#include "Employee.h"
#include "Consumable.h"

using namespace std;

class Cafe; // FORWARD DECLARATION OF CAFE TO AVOID CIRCLE OF PAIN

class KitchenStaff : public Employee {
 protected:
  Consumable food;
  Consumable drink;

 public:
  KitchenStaff();  // default constructor
  void doTask(Customer* customer) override; // NEED TO OVERRIDE THIS FOR ERRORS I NEED HELP
  Consumable get_food();
  Consumable get_drink();

  virtual void doTask(Customer* customer, Cafe* cafe) = 0;  // WANT THIS TO OVERRIDE EMPLOYEE CLASS
  ~KitchenStaff();
};
#endif