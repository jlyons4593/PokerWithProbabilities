#pragma once
#include "UI.h"
#include <SFML/Graphics.hpp>

class HandWonUI: public UI
{
private:
	sf::Text winningText;

	sf::Text playAgainText;
	sf::RectangleShape playAgainButton;

	sf::Text menuText;
	sf::RectangleShape menuButton;

	void initVariables();
	void initialiseWindow();
	void initHandWonText();
	void initHandWonButtons();
	void processPlayerChoices();
	void renderGameObjects(sf::RenderTarget& target);
	

public:

	void update();
	void render();

	HandWonUI();
	~HandWonUI();

};

