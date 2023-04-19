#pragma once
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include <vector>
#include <array>

class PlayerBase{
private:

//total number of chips per player
// int m_redChips;
// int m_blueChips;
// int m_greenChips;
// int m_yellowChips;

int numChips;

//total number of chips player wishes to bet
int m_redChipsToBet;
int m_blueChipsToBet;
int m_greenChipsToBet;
int m_yellowChipsToBet;


Card m_card1;
Card m_card2;



int chipsToBet;


std::vector<Card> bestHand;




public:
void setNumberOfChips(int numberOfChips);

std::string name;

virtual int makeDecision() = 0;

virtual bool payBlind(int amount);


void setCards(std::vector<Card>& cards);


std::vector<Card> getCards() const;

int getChipsToBet();

void initialiseVariables();

void setBestHand(std::vector<Card>& cards);

//constructor destructor 
PlayerBase();
~PlayerBase();

};