#ifndef CLEANER_H
#define CLEARNER_H

#include "Cafe.h"
#include "Employee.h"
#include "Table.h"

class Cleaner : public Employee {
    protected:

    public:
        void doTask(int tableNo);
};

#endif