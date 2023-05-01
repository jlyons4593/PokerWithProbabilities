#pragma once
#include <SFML/Graphics.hpp>
class UI
{
	//mouse variables
	sf::Vector2i mousePositionInt;
	sf::Vector2f mousePositionFloat;
	bool lMBDown;

public:

	// SFML Window variables
	sf::RenderWindow* window;
	sf::VideoMode videomode;

	// SFML Event variable
	sf::Event event;

	bool isGameRunning;

	
	void updateMousePositions();


	void virtual update() = 0;
	void virtual render() = 0;

	void pollEvents();

};

