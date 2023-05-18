

// AggressiveStrategy.h
class HandStrengthStrategy : public Strategy {
public:
    Decision makeDecision(int currentBet, int bettingRound) override {
        // implementation for an aggressive strategy
       
        if (currentBet == 0 ){
            return Decision::Check;    
        }
        return Decision::Call;
    }
};

// ConservativeStrategy.h
class RandomStrategy : public Strategy {
public:
    Decision makeDecision(int currentBet, int bettingRound) override {
        // implementation for a conservative strategy
        if (currentBet == 0 ){
            return Decision::Check;    
        }
        return Decision::Call;
    }
};