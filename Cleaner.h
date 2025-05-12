#ifndef CLEANER_H
#define CLEARNER_H

#include "Cafe.h"
#include "Employee.h"
#include "Table.h"

class Cleaner : public Employee {
    protected:

    public:
        Cleaner();
        void doTask(int customerNumber);
};

#endif