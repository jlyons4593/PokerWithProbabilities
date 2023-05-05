#include "PokerHandsUI.h"

void PokerHandsUI::initVariables()
{
	this->isGameRunning = true;
}

void PokerHandsUI::initialiseWindow()
{
	this->videomode.height = 750;
	this->videomode.width = 560;
	/*this->videomode.getDesktopMode;*/
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(33);
}

void PokerHandsUI::initImage()
{
	this->pokerHandsTexture.loadFromFile("Resources/poker-hands.png");
	this->pokerHandsSprite.setTexture(this->pokerHandsTexture);
	this->pokerHandsSprite.setScale(0.5f,0.5);
}

void PokerHandsUI::renderGameObjects(sf::RenderTarget& target)
{
	target.draw(this->pokerHandsSprite);
}

void PokerHandsUI::update()
{

	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

	

}

void PokerHandsUI::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	this->renderGameObjects(*this->window);

	this->window->display();
}

PokerHandsUI::PokerHandsUI()
{
	initVariables();
	initialiseWindow();
	initImage();
}

PokerHandsUI::~PokerHandsUI()
{
	delete this->window;
}
