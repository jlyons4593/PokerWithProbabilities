#include "PlayerBase.h"

class Player : public PlayerBase{
public:
    int makeDecision() override;

    Player();
    ~Player();
};