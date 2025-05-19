#include "Customer.h"
#include "Table.h"

#include <iostream>
#include <ctime>
#include <random>

Customer::Customer(){
    hunger = 0;
    thirst = 0;
    disgust = 0;
    happiness = 0;
    isActive = false;
    startTime = 0;
}

Customer::Customer(Table tableNo){
    srand(time(0));

    hunger = std::rand() % 5; // generate random integer from 0 to 5
    disgust = 5;
    thirst = std::rand() % 5;

    tableNo = this-> tableNo;

    // to ensure customer score is not 15 on entry to the cafe
    if (hunger == 5 && thirst == 5){
        thirst = 4;
    }
    happiness = hunger+thirst+disgust;
    isActive = false;
    
    startTime = std::time(nullptr);
    endTime = startTime + 120;
}

void Customer::set_isActive(bool state){
    isActive = state;
}

bool Customer::get_isActive(){
    return isActive;
}

void Customer::increase_hunger(){
    // hunger +3
    hunger+=3;
    if (hunger>5){
        hunger = 5;
    }
    happiness = hunger+thirst+disgust;
}

void Customer::decrease_hunger(){
    hunger--;
    if (hunger<0){
        hunger = 0;
    }
    happiness = hunger+thirst+disgust;
}

int Customer::get_hunger(){
    return hunger;
}

void Customer::increase_thirst(){
    // thirst +3
    thirst += 3;
    if (thirst>5){
        thirst = 5;
    }
    happiness = hunger+thirst+disgust;
}

void Customer::decrease_thirst(){
    thirst--;
    if (thirst<0){
        thirst = 0;
    }
    happiness = hunger+thirst+disgust;
}

int Customer::get_thirst(){
    return thirst;
}

void Customer::increase_disgust(){
    // disgust is maxed out to 5
    disgust = 5;
    happiness = hunger+thirst+disgust;
}

void Customer::decrease_disgust(){
    disgust--;
    if (disgust<0){
        disgust = 0;
    }
    happiness = hunger+thirst+disgust;
}

int Customer::get_disgust(){
    return disgust;
}

int Customer::get_happiness(){
    return happiness;
}

Table Customer::get_tableNo(){
    return tableNo;
}

void Customer::set_tableNo(Table tableNo){
    this->tableNo = tableNo;
}