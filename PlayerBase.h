#pragma once
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include <vector>
#include <array>
#include "utils.hpp"



class PlayerBase{
private:

//total number of chips per player
// int m_redChips;
// int m_blueChips;
// int m_greenChips;
// int m_yellowChips;






Card m_card1;
Card m_card2;






std::vector<Card> bestHand;

int numChips;
std::string name;

public:
void setNumberOfChips(int numberOfChips);

void setNumberOfChipsToBet(int chips);

int playerIndex;

int chipsToBet;

int getNumberOfChips();


void setName(std::string name);

std::string getName();

virtual Decision makeDecision(int currentBet, int bettingRound) = 0;

virtual bool payBlind(int amount);

bool takeChips(int chipAmount);

int returnNumberOfChips();

void setCards(std::vector<Card>& cards);

int allIn();

std::vector<Card> getCards() const;

int getChipsToBet();

void initialiseVariables();

void setBestHand(std::vector<Card>& cards);

//constructor destructor 
PlayerBase();
~PlayerBase();

};