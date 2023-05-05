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

void PlayerBase::setNumberOfChipsToBet(int chips){
    std::cout<<"player base "<<std::endl;
    this->chipsToBet = chips;
    std::cout<< "chips set"<<std::endl;
}

void PlayerBase::initialiseVariables()
{

}

void PlayerBase::setName(std::string name){
    this->name = name;
}

int PlayerBase::allIn(){
    int x = this->numChips;
    this->numChips = 0;
    return x;
}

bool PlayerBase::takeChips(int chipAmount){
    if (this->numChips>chipAmount){
        this->numChips -= chipAmount;
        return true;
    }
    return false;
}

int PlayerBase::returnNumberOfChips()
{
    return numChips;
}

std::string PlayerBase::getName(){
    return this->name;
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
        this->numChips = this->numChips - amount;
        return true;
    }
    
}
int PlayerBase::getNumberOfChips(){
    return this->numChips;
}
void PlayerBase::setBestHand(std::vector<Card>& cards){
    this->bestHand = cards;
}

PlayerBase::PlayerBase(){

}
PlayerBase::~PlayerBase(){

}