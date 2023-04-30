#include "PlayerBase.h"
#ifndef PLAYER_H
#define PLAYER_H
class Player : public PlayerBase{
public:
    Decision makeDecision(int currentBet) override;
    bool done;
    void setPlayer();
    Player();
    ~Player();
private:


};


#endif // PLAYER_H