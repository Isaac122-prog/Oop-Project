#include "Player.h"

#include <iostream>

using namespace std;

Player::Player(){
    name = "Player";
    energy = 100;
    maxEnergy = 100;
}

Player::Player(const std::string& name, int maxEnergy){
    name(name), energy(maxEnergy), maxEnergy(maxEnergy) {}
}

void Player::assignTask(const std::string& task) {
    tasks.push_back(task);
}

void Player::performTask() {
    if (!tasks.empty() && energy >= 10) {
        std::cout << name << " is performing: " << tasks[0] << "\n";
        tasks.erase(tasks.begin());
        energy -= 10;
    } else {
        std::cout << name << " is too tired or has no tasks.\n";
    }
}

void Player::rest() {
    energy = maxEnergy;
    std::cout << name << " has rested and regained energy.\n";
}

int Player::getEnergy() const {
    return energy;
}

std::string Player::getName() const {
    return name;
}

void Player::displayStatus() const {
    std::cout << "Player: " << name << ", Energy: " << energy << "/" << maxEnergy << "\n";
    std::cout << "Tasks:\n";
    for (const std::string& task : tasks) {
        std::cout << "- " << task << "\n";
    }
}