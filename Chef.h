#ifndef CHEF_H
#define CHEF_H

#include "Cafe.h"
#include "Employee.h"
#include "Table.h"

class Chef : public Employee {
    protected:
    public:
        // not really sure how to make this work
        void do_task();
};

#endif