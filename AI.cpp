#include "PlayerBase.h"
#include "AI.h"


AI::AI(std::unique_ptr<Strategy> strategy) : strategy_(std::move(strategy)) {}

int AI::makeDecision() {
    return strategy_->makeMove();
}

void AI::setStrategy(std::unique_ptr<Strategy> strategy) {
    strategy_ = std::move(strategy);
}
