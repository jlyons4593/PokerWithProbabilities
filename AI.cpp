#include "PlayerBase.h"
#include "Strategy.h"
#include "AI.h"


AI::AI(Strategy* strategy) : strategy_(strategy){}

int AI::makeDecision(){
    return strategy_->makeDecision();
}



