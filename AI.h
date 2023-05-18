#include "PlayerBase.h"
#include "Strategy.h"
#include "utils.hpp"


class AI : public PlayerBase{
public:
    Decision makeDecision(int currentBet, int bettingRound) override;

   

    AI(Strategy* strategy);
    

private:
    Strategy* strategy_;
    
};