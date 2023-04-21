#ifndef OBSERVER_PATTERN_CPP
#define OBSERVER_PATTERN_CPP

#include "Deck.h"
#include <iostream>
#include <vector>
class Observer {
public:

    virtual void startGame() = 0;
    virtual void endGame() = 0;
    virtual void updateOnBet() = 0;
    virtual void updateCommunityCards() = 0;
    virtual void updatePlayerCards(std::vector<Card>& cards) = 0;
    
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notifyGameStart() {
        for (auto& observer : observers) {
            observer->startGame();
        }
    }
    void notifyGameOver(){
        for (auto &observer : observers)
        {
            observer->endGame();
        }
    }
    void notifyUpdatePlayersCards(std::vector<Card> cards){
        std::cout<<"here"<<std::endl;
        for( auto& observer: observers){
            std::cout<<"observer loop"<<std::endl;
            observer->updatePlayerCards(cards);
            std::cout<<"player cards updated"<< std::endl;

        }
    }
    
};
#endif // OBSERVER_PATTERN_CPP