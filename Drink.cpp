#include "Drink.h"

Drink::Drink(){
    isActive = false;
    numDrink = 0;
}

bool Drink::get_isActive(){
    return isActive;
}
void Drink::set_isActive(bool status){
    isActive = status;
}



Drink::~Drink(){}