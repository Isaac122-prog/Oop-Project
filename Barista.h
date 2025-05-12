#ifndef BARISTA_H
#define BARISTA_H

#include "Employee.h"
#include "KitchenStaff.h"

class Barista : public KitchenStaff {
 protected:
 public:
  Barista();
  void doTask(int customerNumber);
};

#endif