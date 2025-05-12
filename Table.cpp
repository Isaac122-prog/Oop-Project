#include "Table.h"

Table::Table(){
    // table is clean and unoccupied
    isClean = true;
    isOccupied = false;
}

void Table::set_isClean(bool cleanliness){
    isClean = cleanliness;
}

bool Table::get_isClean(){
    return isClean;
}

void Table::set_isOccupied(bool occupation){
    isOccupied = occupation;
}

bool Table::get_isOccupied(){
    return isOccupied;
}