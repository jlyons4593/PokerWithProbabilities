#include "PlayerBase.h"
#include "Strategy.h"
#include "AI.h"
#include <iostream>


AI::AI(Strategy* strategy) : strategy_(strategy){

}

Decision AI::makeDecision(int currentBet, int bettingRound){
    Decision decision = strategy_->makeDecision(currentBet, bettingRound);
    if (decision == Decision::Raise) {
        this->chipsToBet = strategy_->getRaiseAmount();
    }
    std::cout << "Decision = " << int(decision) << std::endl;
    return decision;
}




