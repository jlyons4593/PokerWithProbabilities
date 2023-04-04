#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include "Deck.h"

/*
	Game engine wrapper class
*/
class Game
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
	sf::Text howToPlay;
	sf::Text instructions;

	//deck object
	Deck deck;

	// font
	sf::Font font;

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


	// Private functions

	void initialiseVariables();
	void initialiseWindow();
	void initialiseMenuBar();
	void initialiseMenuScreen();
	void initialisePlayingCards();

	//test functions
	void deckLoader();
	
	

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Accessors
	const bool isGameRunning() const;


	

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

