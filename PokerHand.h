#pragma once
#include "Utils.h"
#include "PokerHandUI.h"
#include "ObserverPattern.cpp"
#include "PlayerBase.h"
#include "AI.h"
#include "Strategy.h"
#include "SimpleStrategies.h"



class IPokerHandUI;
class Deck;
class Card;

class PokerHand: public Subject
{
private:
	// Community Cards
	std::vector<Card> communityCards;

	//Update UI
	void updateUI();

	// Change State
	void setState(GameState newState) {
		currentState = newState;
		updateUI();
	}

	void setCardsAndBlinds();

	void payBlinds();
	void setPlayerCards();
	void setCommunityCards();

	// Game State
	GameState currentState;

	// UI pointer
	PokerHandUI* ui;

	//Game logic variables
	int chipsPerPlayer;

	// player variables
	int numOfPlayers;
	std::vector<PlayerBase*> players;

	//  Function that begins the first sequence in the Poker Hand
	void beginGame();


	// Function to initialise poker variables
	void initVariables();
	void initPlayers();

	

	// Create Deck
	Deck deck;




public:

	//  Function to initialise and load the PokerHand UI
	void loadUI();
	

	//game functions
	void startHand();
	
	


	//  Constructor Destructor for the initialisation of the Poker Game
	PokerHand();
	~PokerHand();


};

