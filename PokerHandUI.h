#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "Deck.h"
class IPokerHandUI;

class PokerHandUI : public UI
{
private:
	
	Deck deck;

	//  Startup Functions
	void initVariables();
	void initWindow();
	void initMenuBar();

	//  Menu Bar
	sf::RectangleShape menuBar;
	
	//  Menu Bar Text variables
	sf::Text title;
	sf::Text instructions;
	sf::Text settings;

	// community cards Sprites
	sf::Sprite communityCard1;
	sf::Sprite communityCard2;
	sf::Sprite communityCard3;
	sf::Sprite communityCard4;
	sf::Sprite communityCard5;

	//Player Card Sprites
	sf::Sprite player1card1;
	sf::Sprite player1card2;
	sf::Sprite player2card1;
	sf::Sprite player2card2;
	sf::Sprite player3card1;
	sf::Sprite player3card2;
	sf::Sprite player4card1;
	sf::Sprite player4card2;


	// Poker buttons 
	sf::RectangleShape pokerHandsButton;
	sf::Text pokerHandsText;

	sf::Text gameStateText;
	sf::RectangleShape gameStateRect;

	sf::Text readyUpText;
	sf::RectangleShape readyUpButton;

	sf::Text foldText;
	sf::RectangleShape foldButton;
	bool hasFolded;

	//betting buttons
	sf::Text raiseText;
	sf::RectangleShape raiseButton;

	sf::Text raiseIncrementText;
	sf::RectangleShape raiseIncrementButton;

	sf::Text raiseDecrementText;
	sf::RectangleShape raiseDecrementButton;

	sf::Text raiseDoubleIncrementText;
	sf::RectangleShape raiseDoubleIncrementButton;

	sf::Text raiseDoubleDecrementText;
	sf::RectangleShape raiseDoubleDecrementButton;

	sf::Text raiseAmount;
	sf::RectangleShape raiseBox;
	sf::String chipsRaisedString;

	//oddsView variables
	sf::Text oddsViewText;
	sf::RectangleShape oddsViewButton;


	// Render functions
	void renderObjects(sf::RenderTarget& target);
	
	void initPlayScreenObjects();
	void initCommunityCardSprites();
	void initPlayerCardsSprites();
	void initGeneralPlayButtons();
	void initReadyUpButton();
	void initBettingObjects();


public:

	bool isGameRunning;

	void update() override;
	void render() override;

	PokerHandUI();
	~PokerHandUI();
};

