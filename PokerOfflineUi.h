#pragma once
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "ObserverPattern.cpp"
#include "Poker.h"
#include "utils.hpp"
#include "Player.h"

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

	//Players Money
	sf::Text playerChips;

	sf::Text AIChips;
	sf::Text AI2Chips;
	sf::Text AI3Chips;
	sf::Text AI4Chips;

	std::vector<sf::Text> playerCash;

	// Player Names
	sf::Text playerName;
	sf::Text AIName;
	sf::Text AI2Name;
	sf::Text AI3Name;
	sf::Text AI4Name;

	//Player statuses
	sf::Text playerStatus;
	sf::Text AIStatus;
	sf::Text AI2Status;
	sf::Text AI3Status;
	sf::Text AI4Status;

	std::vector<sf::Text> playerNames;
	std::vector<sf::Text> statuses;

	//PLayer chip amounts to display
	int playerChipsInt;
	int AIChipsInt;
	int AI2ChipsInt;
	int AI3ChipsInt;
	int AI4ChipsInt;

	std::vector<int> playerCashInt;

	int playerBetAmount;

	//Pot
	sf::Text potText;
	int potAmount;

	//current betHigh
	int groupHighBet;
	int playerHighBet;

	int chipsRaisedInt;
	bool raiseBoxActive;
	
	// sf::Text checkButton;
	// sf::RectangleShape checkButton;
	bool keyDown;

	Deck deck;

	//TitleText
	sf::Text title;
	sf::Text settings;
	sf::Text instructions;

	//Font
	sf::Font font;

	void launchPoker();
	//game logic
	

	
	
	//private functions
	void setPlayerChips(int chips);

	void initialisePot();
	void initialiseVariables();
	void initialiseWindow();
	void initialiseMenuBar();
	void initialisePlayScreenObjects();
	void initialiseCommunityCardSprites();
	void initialisePlayerCardsSprites();
	void initialiseGeneralPlayButtons();
	void initialisePlayerChips();
	void initialiseReadyUpButton();
	void initialiseGameStateButton();
	void initialisePlayerStatuses();
	void initialiseFoldButton();
	void initialiseBettingObjects();
	void renderText(sf::RenderTarget& target);
	void renderGameObjects(sf::RenderTarget& target);
	void updatePlayerUIs();
	void updatePot();
	void updateMousePositions();
	void updatePlayerChips();
	void pollEvents();
	void processStartingClick();
	void processPlayerChoices();
	void processReadyUp();
	
	void processStateSwitch();

	//reference to player object
	Player* player;

	bool readyUp;

	Poker* pokerGame;

	Decision decision;

	std::thread t1;

public:
	//Constructor Destructor
	PokerOfflineUi();
	virtual ~PokerOfflineUi();

	//override functions from observer
    void startGame() override;
    void endGame() override;
	Decision waitForPlayerDecision(int currentBet);
	void setPlayer(Player* player) override;
    void updateOnBet() override;
	void startBetting();
	void resetReadyAndDecision();
	void updateCommunityCardsOnFlop(Card& c1,Card& c2, Card& c3) override;
	void updateCommunityCardsOnTurn(Card& card) override;
	void updateCommunityCardsOnRiver(Card& card) override;
 	void updatePlayerCards(std::vector<Card> cards) override;
	void foldPlayer(int playerIndex) override;
	void raisePlayer(int playerIndex, int raiseAmount)override;
	void checkPlayer(int playerIndex) override;
	void callPlayer(int playerIndex, int chipAmount) override;
	void allInPlayer(int playerIndex) override;

	bool hasStarted;
	void initialUpdate();
	void render();
	void update();
	const bool isGameRunning() const;

};

