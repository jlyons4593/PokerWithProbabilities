

// AggressiveStrategy.h
class HandStrengthStrategy : public Strategy {
public:
    int makeDecision() override {
        // implementation for an aggressive strategy
        return 1;
    }
};

// ConservativeStrategy.h
class RandomStrategy : public Strategy {
public:
    int makeDecision() override {
        // implementation for a conservative strategy
        return 2;
    }
};