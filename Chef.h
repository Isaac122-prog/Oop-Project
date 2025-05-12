#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"
#include "KitchenStaff.h"

class Chef : public KitchenStaff {
 protected:
 public:
  Chef();

  void do_task();
};

#endif