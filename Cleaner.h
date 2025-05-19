#ifndef CLEANER_H
#define CLEARNER_H

#include "Employee.h"
#include "Table.h"
#include "Customer.h"

class Cleaner : public Employee {
    protected:

    public:
        Cleaner();
        void doTask(Customer* customer) override;
};

#endif