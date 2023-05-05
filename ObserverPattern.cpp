#ifndef OBSERVER_PATTERN_CPP
#define OBSERVER_PATTERN_CPP

#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <vector>
class Observer {
public:

    virtual void startGame() = 0;
    virtual void endGame() = 0;
    virtual void setPlayer(Player* player) = 0;
    virtual void updateOnBet() = 0;
    virtual void updateCommunityCardsOnFlop(Card& c1,Card& c2,Card& c3) = 0;
    virtual void updateCommunityCardsOnTurn(Card& card) = 0;
    virtual void updateCommunityCardsOnRiver(Card& card) = 0;
    // virtual void updatePlayerBettingAmount(int index, int bet);
    virtual void updatePlayerCards(std::vector<Card> cards) = 0;
    virtual void foldPlayer(int playerIndex) = 0;
    virtual void callPlayer(int playerIndex, int chipAmount) = 0;
    virtual void checkPlayer(int playerIndex) = 0;
    virtual void allInPlayer(int playerIndex) = 0;
    virtual void raisePlayer(int playerIndex, int raiseAmount)=0;
    
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
    void setPlayer(Player* player){
        for (auto& observer : observers) {
            observer->setPlayer(player);
        }
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
        std::cout<<"In notify player Cards function"<<std::endl;
        for(auto& observer: observers){
            std::cout<<observer<<std::endl;
            observer->updatePlayerCards(cards);
            
            std::cout<<"player cards updated"<< std::endl;

        }
    }
    void notifyUpdateCommunityCardsOnFlop(Card& c1,Card& c2,Card& c3 ){
        for( auto& observer: observers){
            observer->updateCommunityCardsOnFlop(c1, c2, c3);

        }
    }
    void notifyUpdateCommunityCardsOnTurn(Card& c1){
        for( auto& observer: observers){
            observer->updateCommunityCardsOnTurn(c1);

        }
    }
    void notifyUpdateCommunityCardsOnRiver(Card& c1 ){
        for( auto& observer: observers){
            observer->updateCommunityCardsOnRiver(c1);

        }
    }
    void notifyPlayerFolded(int playerIndex){
        for (auto& observer: observers){
            observer->foldPlayer(playerIndex);
        }
    }
    void notifyPlayerCall(int playerIndex, int chipAmount){
        for (auto& observer: observers){
            observer->callPlayer(playerIndex, chipAmount);
            std::cout<<"in notifyPlayerCall "<<chipAmount<<std::endl;;
        }
    }
    void notifyPlayerCheck(int playerIndex){
        for (auto& observer: observers){
            observer->checkPlayer(playerIndex);
        }
    }
    void notifyPlayerAllIn(int playerIndex){
        for (auto& observer: observers){
            observer->allInPlayer(playerIndex);
        }
    }
    
};
#endif // OBSERVER_PATTERN_CPP