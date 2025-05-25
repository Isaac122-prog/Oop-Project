#include "Player.h"

#include <iostream>

using namespace std;

//.Sets name and energy levels
Player::Player(){
    name = "Player"; //Name of the player
    energy = 100; //Current energy of the player
    maxEnergy = 100; //Maximum energy of Player
}

// Allows for customisation such as name and energy
Player::Player(const std::string& name, int maxEnergy):
    name(name), energy(maxEnergy), maxEnergy(maxEnergy){} //sets the values


// Assigns tasks to the players task list
void Player::assignTask(const std::string& task) {
    tasks.push_back(task); // adds tasks
}

//Performs the task if the energy is above 10
void Player::performTask() {
    //if there is at least one task and energy level is above 10, then task will be performed
    if (!tasks.empty() && energy >= 10) {
        std::cout << name << " is performing: " << tasks[0] << "\n";
        tasks.erase(tasks.begin()); //erases the task frfom the vector
        energy -= 10; //energy goes down by 10 once task is done
    } else {
        std::cout << name << " is too tired or has no tasks.\n"; //if there is not enough energy or no tasks to be done
    }
}

//Restores energy by resting and ensures that energy returns to the max level
void Player::rest() {
    energy = maxEnergy; //Energy restores to the maximum energy level
    std::cout << name << " has rested and regained energy.\n";
}

//returns the current energy
int Player::getEnergy() const {
    return energy;
}

//return max energy for testing
int Player::getMaxEnergy() const {
    return maxEnergy;
}

// returns the name of the player
std::string Player::getName() const {
    return name;
}

// displays the players name, energy level and tasks.
void Player::displayStatus() const {
    std::cout << "Player: " << name << ", Energy: " << energy << "/" << maxEnergy << "\n";
    std::cout << "Tasks:\n";
    for (const std::string& task : tasks) {
        std::cout << "- " << task << "\n"; //displays the task in a list 
    }
}