#ifndef PLAYER_H
#define PLAYER_H

#include "Cafe.h"

using namespace std;

class Player : public Cafe {
    protected:

    public:
        Player();
        Player(int max);

        void assignTask();
};

#endif