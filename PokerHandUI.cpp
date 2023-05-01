#include "PokerHandUI.h"

void PokerHandUI::initVariables()
{
	this->isGameRunning = true;
}

void PokerHandUI::initWindow()
{
	this->videomode.height = 1080;
	this->videomode.width = 1920;

	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

void PokerHandUI::update()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

}

void PokerHandUI::render()
{
	// Coloring the window
	this->window->clear(sf::Color(0, 100, 0));
	

	// Displaying window
	this->window->display();

}

PokerHandUI::PokerHandUI()
{
	this->initVariables();
	this->initWindow();
}

PokerHandUI::~PokerHandUI()
{
}
