#pragma once
#include "UI.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
class HandLostUI : public UI
{
private:
	sf::Text winningText;

	sf::Text playAgainText;
	sf::RectangleShape playAgainButton;

	sf::Text menuText;
	sf::RectangleShape menuButton;

	void initVariables();
	void initialiseWindow();
	void initHandLostText();
	void initHandLostButtons();
	void processPlayerChoices();
	void renderGameObjects(sf::RenderTarget& target);
	void startMenu();

public:

	void update();
	void render();

	HandLostUI();
	~HandLostUI();

};

