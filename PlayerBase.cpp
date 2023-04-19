#include "PlayerBase.h"
#include <iostream>

void PlayerBase::setNumberOfChips(int numberOfChips)
{
    
    this->numChips =numberOfChips;
    
}

void PlayerBase::setCards(std::vector<Card>& cards)
{
    this->m_card1 = cards[0];
    this->m_card2 = cards[1];
}

std::vector<Card> PlayerBase::getCards() const{
    std::vector<Card> cards;
    cards.push_back(this->m_card1);
    cards.push_back(this->m_card2);
    return cards;
}


void PlayerBase::initialiseVariables()
{

}


int PlayerBase::getChipsToBet(){
    return this->chipsToBet;
}

bool PlayerBase::payBlind(int amount){
    std::cout<< "number of red chips = "<< this->numChips << std::endl;
    if (amount > this->numChips){
        return false;
    }
    else{
        return true;
    }
    
}

void PlayerBase::setBestHand(std::vector<Card>& cards){
    this->bestHand = cards;
}

PlayerBase::PlayerBase(){

}
PlayerBase::~PlayerBase(){

}