#include "Customer.h"

#include <iostream>
#include <chrono>
#include <random>

Customer::Customer(){
    // taken from chat gpt to randomise numbers for hunger and thirst
    std::random_device rd;                          // non-deterministic seed
    std::mt19937 gen(rd());                         // Mersenne Twister engine
    std::uniform_int_distribution<> dist(1, 4);     // range: 1 to 4 inclusive

    hunger = dist(gen);
    disgust = 5;
    thirst = dist(gen);
    // to ensure customer score is not 15 on entry to the cafe
    if (hunger == 5 && thirst == 5){
        thirst = 4;
    }
    happiness = hunger+thirst+disgust;
    isActive = false;
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