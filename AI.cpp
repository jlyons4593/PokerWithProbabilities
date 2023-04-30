#include "PlayerBase.h"
#include "Strategy.h"
#include "AI.h"


AI::AI(Strategy* strategy) : strategy_(strategy){

}

Decision AI::makeDecision(int currentBet){
    return strategy_->makeDecision(currentBet);
}




