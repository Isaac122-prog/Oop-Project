#include "Player.h"
#include "Cafe.h"

#include <iostream>

using namespace std;

Player::Player(){};

void Player::assignTask(){
    // i don't know how to do this
}

void Player::viewPerformance(){
    for (int i=0; i<get_maxCustomers(); i++){
        cout << "customer " << i << " score: " << get_customer(i).get_happiness() << endl;
    }
}