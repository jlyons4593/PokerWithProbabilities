#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


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

	// menu objects

	sf::RectangleShape menuBar;
	sf::Text playVsAi;
	sf::Text settings;
	sf::Text howToUse;
	sf::Text instructions;


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
	void render();

};

