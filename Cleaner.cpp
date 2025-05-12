#include "Cleaner.h"
#include "Employee.h"
#include "Cafe.h"
#include "Table.h"

#include <chrono>
#include <thread>

using namespace std;

void Cleaner::doTask(int tableNo){
    // the cleaner's task is to clean this specific table

    // wait for 15 seconds -> FROM CHAT GPT
    this_thread::sleep_for(chrono::seconds(10));  

    // setting the isClean property from table class to ture
    tables[tableNo].set_isClean(true);

}