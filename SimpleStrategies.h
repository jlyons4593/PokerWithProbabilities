

// AggressiveStrategy.h
class HandStrengthStrategy : public Strategy {
public:
    Decision makeDecision(int currentBet) override {
        // implementation for an aggressive strategy
        return Decision::Raise;
        
    }
};

// ConservativeStrategy.h
class RandomStrategy : public Strategy {
public:
    Decision makeDecision(int currentBet) override {
        // implementation for a conservative strategy
        return Decision::Call;
    }
};