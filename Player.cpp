#include "Player.h"
#include <iostream>
#include "utils.hpp"
#include "PokerOfflineUi.h"
#include "PokerOfflineUiSingleton.h"


void Player::setPlayer(){
    

}
Decision Player::makeDecision(int currentBet) {
    std::cout<<"frick";
        

    PokerOfflineUiSingleton& singleton = PokerOfflineUiSingleton::getInstance();
    PokerOfflineUi* ui = singleton.getPokerOfflineUi();
    ui->setPlayer(this);
    ui->resetReadyAndDecision();
    

    Decision decision= ui->waitForPlayerDecision(currentBet);

    std::cout<<"Player bet amount = "<<this->chipsToBet<<std::endl;
    
   

    
    // code to display the UI and wait for user input
    // when user input is received, set the result and signal the condition variable
    // the signal will wake up the thread that is waiting for the result
    // make sure to lock the mutex before modifying the shared variables
    // and unlock it before waiting on the condition variable

  

    
    return decision;


    

}


Player::Player(){
    this->chipsToBet = 0;
}
Player::~Player(){
    
}