#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player {
protected:
    std::string name;
    int energy;
    int maxEnergy;
    std::vector<std::string> tasks;

public:
    Player();
    Player(const std::string& name, int maxEnergy);

    void assignTask(const std::string& task);
    void performTask();
    void rest();

    int getEnergy() const;
    std::string getName() const;
    void displayStatus() const;
};

#endif
