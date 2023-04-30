#ifndef STRATEGY_H
#define STRATEGY_H
#include "Player.h"

class Strategy {
public:
    virtual Decision makeDecision(int currentBet) = 0;
};


#endif // STRATEGY_H