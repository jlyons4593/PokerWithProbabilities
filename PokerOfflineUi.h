#pragma once
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "ObserverPattern.cpp"
#include "Poker.h"
#include <thread>
class PokerOfflineUi: public Observer
{
private:

	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event event;

	//Misc
	bool lMBDown;

	//mouse variables
	sf::Vector2i mousePositionInt;
	sf::Vector2f mousePositionFloat;


	//Game objects
	
	sf::RectangleShape menuBar;

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
	// sf::Sprite player5card1;
	// sf::Sprite player5card2;
	// sf::Sprite player6card1;
	// sf::Sprite player6card2;
	// sf::Sprite player7card1;
	// sf::Sprite player7card2;
	// sf::Sprite player8card1;
	// sf::Sprite player8card2;

	//// General Play Buttons
	////OddsView
	//sf::RectangleShape oddsViewButton;
	//sf::Text oddsViewText;
	sf::RectangleShape pokerHandsButton;
	sf::Text pokerHandsText;

	////Players buttons
	//sf::RectangleShape raiseButton;
	//sf::Text raiseButtonText;
	//sf::RectangleShape checkButton;
	//sf::Text checkButtonText;

	sf::Text gameStateText;
	sf::RectangleShape gameStateRect;

	Deck deck;

	//TitleText
	sf::Text title;
	sf::Text settings;
	sf::Text instructions;

	//Font
	sf::Font font;

	void launchPoker();
	//game logic
	int potAmount;

	
	
	//private functions

	void initialiseVariables();
	void initialiseWindow();
	void initialiseMenuBar();
	void initialisePlayScreenObjects();
	void initialiseCommunityCardSprites();
	void initialisePlayerCardsSprites();
	void initialiseGeneralPlayButtons();
	void initialisePlayerButtons();
	void initialiseGameStateButton();
	void renderText(sf::RenderTarget& target);
	void renderGameObjects(sf::RenderTarget& target);
	void updateMousePositions();
	void pollEvents();
	void processStartingClick();
	

	Poker* pokerGame;

	std::thread t1;

public:
	//Constructor Destructor
	PokerOfflineUi();
	virtual ~PokerOfflineUi();

	//override functions from observer
    void startGame() override;
    void endGame() override;
    void updateOnBet() override;
	void updateCommunityCards() override;
 	void updatePlayerCards(std::vector<Card>& cards) override;

	bool hasStarted;
	void initialUpdate();
	void render();
	void update();
	const bool isGameRunning() const;

};

