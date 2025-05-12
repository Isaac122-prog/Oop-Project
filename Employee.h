#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Cafe.h"

class Employee : public Cafe {
    protected:
        bool isBusy;
    public:
        virtual void doTask();
};

#endif