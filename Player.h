#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

//Player class with attributes of name, energy and tasks
class Player {
protected:
    std::string name;
    int energy;
    int maxEnergy;
    std::vector<std::string> tasks;

public:
    Player();
    Player(const std::string& name, int maxEnergy); // constructor to set name and max energy 

    void assignTask(const std::string& task); // adds a task into the list of things needed to do
    void performTask(); // Does the task assigned
    void rest(); // rests a players energy to max energy

    int getEnergy() const; //Grabs the current energy level
    std::string getName() const; //Grabs the player name
    void displayStatus() const; //Displays players current status
};

#endif
