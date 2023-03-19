#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>

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

	// font
	sf::Font font;

	


	// Private functions

	void initialiseVariables();
	void initialiseWindow();
	void initialiseMenuBar();
	void initialiseMenuScreen();
	
	

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
	void processMenuChoices();
	void updateMousePositions();

};

