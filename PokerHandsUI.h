#pragma once
#include "SFML/Graphics.hpp"
#include "UI.h"
class PokerHandsUI: public UI
{
private:
	

	sf::Texture pokerHandsTexture;
	sf::Sprite pokerHandsSprite;


	void initVariables();
	void initialiseWindow();
	void initImage();
	
	void renderGameObjects(sf::RenderTarget& target);


public:

	void update();
	void render();

	PokerHandsUI();
	~PokerHandsUI();

};


