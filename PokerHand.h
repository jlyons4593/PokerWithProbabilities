#pragma once
#include "Utils.h"
#include "PokerHandUI.h"
class PokerHand
{
private:
	

	// Function to initialise poker variables
	void initVariables();


public:

	//  Function to initialise and load the PokerHand UI
	void loadUI();


	//  Function that begins the first sequence in the Poker Hand
	void beginGame();
	


	//  Constructor Destructor for the initialisation of the Poker Game
	PokerHand();
	~PokerHand();


};

