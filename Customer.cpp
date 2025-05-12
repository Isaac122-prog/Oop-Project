#include "Customer.h"

#include <iostream>
#include <chrono>

Customer::Customer(){
    hunger = 0;
    disgust = 0;
    thirst = 0;
    happiness = 0;
    isActive = false;
}

void Customer::set_isActive(bool state){
    isActive = state;
}

bool Customer::get_isActive(){
    return isActive;
}

void Customer::increase_hunger(){
    // max out hunger
    hunger=5;
}

void Customer::decrease_hunger(){
    hunger--;
}

int Customer::get_hunger(){
    return hunger;
}

void Customer::increase_thirst(){
    // max out thirst
    thirst = 5;
}

void Customer::decrease_thirst(){
    thirst--;
}

int Customer::get_thirst(){
    return thirst;
}

void Customer::increase_disgust(){
    // max out disgust
    disgust = 5;
}

void Customer::decrease_disgust(){
    disgust--;
}

int Customer::get_disgust(){
    return disgust;
}