#include <random>

// AggressiveStrategy.h
class HandStrengthStrategy : public Strategy {
public:
    Decision makeDecision(int currentBet, int bettingRound) override {
        // implementation for an aggressive strategy
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 10);

        
        int randomNum = dis(gen);
        std::cout <<"Betting round =" << bettingRound << std::endl;
        if (bettingRound > 1) {
            if (currentBet == 0) {
                return Decision::Check;
            }
            return Decision::Call;
        }
        std::cout << "Random num is " << randomNum << std::endl;
        if (randomNum < 5) {
            return Decision::Raise;
        }
        /*else if (randomNum > 2 && randomNum << 7) {
            return Decision::Raise;
        }*/
        else {
            if (currentBet == 0) {
                return Decision::Check;
            }
            return Decision::Call;
        }
        
        
    }
    int getRaiseAmount()override {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(10, 20);

        int randomNum = dis(gen);
        return randomNum;
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
    int getRaiseAmount()override {
        return 5;
    }
};