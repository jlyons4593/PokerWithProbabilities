#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include "UI.h"
#include "Deck.h"

/*
	Game engine wrapper class
*/
class Game: UI
{
private:

	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event event;


	//mouse variables
	sf::Vector2i mousePositionInt;
	sf::Vector2f mousePositionFloat;
	bool lMBDown;

	// menu objects
	sf::RectangleShape menuBar;

	//TitleText
	sf::Text title;
	

	// menu Text
	sf::Text playVsAi;
	sf::Text settings;
	sf::Text disclaimer;
	sf::Text instructions;
	sf::Text practice;

	//deck object
	Deck deck;

	

	// Menu Playing cards textures
	sf::Texture heartsTen;
	sf::Texture heartsJack;
	sf::Texture heartsQueen;
	sf::Texture heartsKing;
	sf::Texture heartsAce;

	// Menu playing card sprites
	sf::Sprite ten;
	sf::Sprite jack;
	sf::Sprite queen;
	sf::Sprite king;
	sf::Sprite ace;

	//back button variables
	sf::RectangleShape backButton;
	sf::Text backText;

	// Disclaimer variables
	sf::Text disclaimerTitle;
	sf::Text disclaimerText;
	

	// Instruction variables
	sf::Text instructionText;
	sf::Text instructionTitle;

	// Settings variables
	sf::Text settingsText;
	sf::Text playerMoneyText;
	sf::Text volumeText;
	sf::Text volumeDisplayText;
	sf::Text playerMoneyDisplayText;
	sf::Text volumeIncrementText;
	sf::Text volumeDecrementText;
	sf::Text playerMoneyIncrementText;
	sf::Text playerMoneyDecrementText;

	sf::RectangleShape volumeDisplayRect;
	sf::RectangleShape playerMoneyDisplayRect;

	sf::RectangleShape volumeIncrementButton;
	sf::RectangleShape volumeDecrementButton;
	sf::RectangleShape playerMoneyIncrementButton;
	sf::RectangleShape playerMoneyDecrementButton;

	//apply changes button
	sf::Text applyChangesText;
	sf::RectangleShape applyChangesButton;

	int volume;
	int playerMoney;


	int masterPlayerMoney;

	// Private functions
	
	void initialiseVariables();
	void initialiseWindow();
	void initialiseMenuBar();
	void initialiseMenuScreen();
	void initialisePlayingCards();


	//Disclaimer scene
	bool inDisclaimer;
	void initialiseDisclaimerUI();
	void updateDisclaimer();
	void renderDisclaimer();
	void handleDisclaimerUpdate();

	//Instructions scene
	bool inInstruction;
	void initialiseInstructionUI();
	void updateInstruction();
	void renderInstruction();
	void handleInstructionUpdate();

	//Settings scene
	bool inSettings;
	void initialiseSettingsUI();
	void updateSettings();
	void renderSettings();
	void handleSettingsUpdate();

	//test functions
	//void deckLoader();
	
	

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool isGameRunning() const;


	
	sf::RenderWindow* getWindow() {
		return window;
	}
	//functions
	void pollEvents();
	void update();
	void UpdateText();
	void render();
	void renderMenuText(sf::RenderTarget& target);
	void renderMenuSprites(sf::RenderTarget& target);
	void processMenuChoices();
	void updateMousePositions();

};

