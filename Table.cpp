#include "Table.h"

Table::Table(){
    isClean = true;
}

void Table::set_isClean(bool cleanliness){
    isClean = cleanliness;
}

bool Table::get_isClean(){
    return isClean;
}