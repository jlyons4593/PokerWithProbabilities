

// AggressiveStrategy.h
class HandStrengthStrategy : public Strategy {
public:
    int makeDecision() override {
        // implementation for an aggressive strategy
    }
};

// ConservativeStrategy.h
class RandomStrategy : public Strategy {
public:
    int makeDecision() override {
        // implementation for a conservative strategy
    }
};