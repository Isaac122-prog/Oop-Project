#include "Food.h"

Food::Food(){
    isActive = false;
}

bool Food::get_isActive(){
    return isActive;
}
void Food::set_isActive(bool status){
    isActive = status;
}

Food::~Food(){}