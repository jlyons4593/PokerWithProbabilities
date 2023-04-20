#pragma once
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "PlayerBase.h"
#include "ObserverPattern.cpp"
#include <vector>
#include <algorithm>

class Poker: public Subject{
private:

//initialisation variables
int m_numOfPlayers;

enum HandRank {
    HIGH_CARD = 0,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};


//cards variables
Deck m_currentDeck;

std::vector<Card> communityCards;

Card communityCard1;
Card communityCard2;
Card communityCard3;
Card communityCard4;
Card communityCard5;

//players vector
std::vector<PlayerBase*> players;
std::vector<PlayerBase*> playersInHand;

//chip variables
int numOfRedChips;
int numOfYellowChips;
int numOfGreenChips;
int numOfBlueChips;


//blind logic
int blindCounter;
int bigBlind;
int smallBlind;


// pot
int pot;

int moneyPerPlayer;

bool playersAreReady;

void initializeVariables();
void initializePlayers();
void setCommunityCards();

void dealCards();
std::vector<PlayerBase*> determineHandWinner();
void setPlayerCards();
void hand();
void setPlayerBlinds();
bool compareByValue(const Card& a, const Card& b);

// determine hands rank
bool isStraightFlush(PlayerBase *player);
bool isFourOfAKind(PlayerBase *player);
bool isFullHouse(PlayerBase *player);
bool isFlush(PlayerBase *player);
bool isStraight(PlayerBase *player);
bool isThreeOfAKind(PlayerBase *player);
bool isTwoPair(PlayerBase *player);
bool isPair(PlayerBase *player);

//bankrupt Player logic

void removePlayerFromHand(PlayerBase* player);



void fullGame();

public:
//Constructors and Destructors
void startGame();

Poker();
~Poker();


};