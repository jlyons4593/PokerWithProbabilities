#ifndef POKEROFFLINEUI_H
#define POKEROFFLINEUI_H
#pragma once
#include <SFML/Graphics.hpp>
#include "Deck.h"
#include "ObserverPattern.cpp"
#include "Poker.h"
#include "utils.hpp"
#include "Player.h"
#include "UI.h"
#include "OddsView.h"
#include <thread>


class PokerOfflineUi: public Observer, public UI
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

	//// General Play Buttons
	////OddsView
	sf::RectangleShape oddsViewButton;
	sf::Text oddsViewText;

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
	int chipsPerPlayer;

	int playerChipsInt;
	int AIChipsInt;
	int AI2ChipsInt;
	int AI3ChipsInt;
	int AI4ChipsInt;

	int playerBetAmount;

	//Pot
	sf::Text potText;
	int potAmount;

	//current betHigh
	int groupHighBet;
	int playerHighBet;

	int chipsRaisedInt;
	bool raiseBoxActive;

	bool keyDown;

	Deck deck;

	//TitleText
	sf::Text title;
	sf::Text oddsViewInstructions;
	sf::Text instructions;

	//intruction variables
	sf::RectangleShape backButton;
	sf::Text backText;
	sf::Text instructionTitle;
	sf::Text instructionText;
	void initialiseInstructions();

	bool inInstruction;
	void updateInstruction();
	void renderInstruction();
	void handleInstructionUpdate();

	//odds view help variables
	sf::Text oddsInstructionTitle;
	sf::Text oddsInstructionText;
	bool inOddsViewHelp;
	void updateOddsViewHelp();
	void renderOddsViewHelp();

	

	//handling for displaying pokerHands

	bool isLookingAtHands;

	sf::Sprite pokerHandsSprite;
	sf::Texture pokerHandsTexture;
	sf::RectangleShape closePokerHandsButton;
	sf::Text closePokerHandsText;


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
	void updatePlayerChipsDisplay();
	void pollEvents();
	void processStartingClick();
	void processPlayerChoices();
	void processReadyUp();
	void showPokerHands();
	void processStateSwitch();
	void processPokerHandsButton();
	void processOddsViewButton();
	void runPokerHandsWindow();
	void runOddsViewWindow();
	void launchOddsView();
	void updatePlayerStatus(int playerIndex, std::string string);
	void updatePlayerChips(int playerIndex, int currentBet);

	void setWaitingStatuses();

	

	// ShowDown functions
	void showdownUpdateCards(std::vector<Card> aiCards, std::vector<Card> ai2Cards, std::vector<Card> ai3Cards);
	void showDownRemoveButtons();

	bool isPractice;

	//reference to player object
	Player* player;

	bool readyUp;

	bool isPokerHandsOpen;
	bool isOddsViewOpen;

	std::thread pokerHandsThread;
	std::thread oddsViewThread;
	std::thread launchOddsViewThread;

	Poker* pokerGame;

	OddsView* oddsView_;
	//AudioManager* audioManager;

	Decision decision;

	std::thread t1;

public:
	//Constructor Destructor
	PokerOfflineUi();
	virtual ~PokerOfflineUi();

	void launchPoker();
	void launchUI();

	//override functions from observer
    void startGame() override;
	void winGame()override;
	void loseGame()override;
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
	void updatePot(int pot)override;
	void updateShowdown(std::vector<Card> aiCards, std::vector<Card> ai2Cards, std::vector<Card> ai3Cards, int winner) override;


	// Function for deciding between Practice mode and normal
	void setVariables(int money, bool isPractice);

	bool hasStarted;
	void initialUpdate();
	void render();
	void update();
	const bool isGameRunning() const;

};

#endif