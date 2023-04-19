#include "PlayerBase.h"
#include "Strategy.h"
#include "AI.h"


AI::AI(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy)){}

int AI::makeDecision(){
    return strategy_->makeDecision();
}

void AI::setStrategy(std::unique_ptr<Strategy> strategy) {
    strategy_ = std::move(strategy);
}

