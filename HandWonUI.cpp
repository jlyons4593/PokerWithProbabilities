#include "HandWonUI.h"

void HandWonUI::initVariables()
{
	this->isGameRunning = true;
	this->font.loadFromFile("Fonts/Roboto-Black.ttf");
}
void HandWonUI::initialiseWindow()
{
	this->videomode.height = 720;
	this->videomode.width = 1280;
	
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void HandWonUI::initHandWonText()
{
	std::string string = "Congratulations you won the hand!!\n      Do you want to play again?";
	
	this->setTextProperties(this->winningText, string, sf::Vector2f(this->videomode.width / 2,this->videomode.height / 2 -150),  int(this->videomode.width / 50), sf::Color::Black);
}

void HandWonUI::initHandWonButtons()
{
	// Menu
	this->setRectangleProperties(this->menuButton, sf::Vector2f(this->videomode.width / 10, this->videomode.height / 15), sf::Vector2f(this->videomode.width / 2-100, 400.f), sf::Color::Red);
	this->setTextProperties(this->menuText, "Menu", sf::Vector2f(this->menuButton.getPosition()), int(this->videomode.width / 80), sf::Color::Black);
	
	//Play again
	this->setRectangleProperties(this->playAgainButton, sf::Vector2f(this->videomode.width / 10, this->videomode.height / 15), sf::Vector2f(this->videomode.width / 2+100, 400.f), sf::Color::Red);
	this->setTextProperties(this->playAgainText, "Play Again!", sf::Vector2f(this->playAgainButton.getPosition()), int(this->videomode.width / 80), sf::Color::Black);
}

void HandWonUI::processPlayerChoices()
{
}

void HandWonUI::renderGameObjects(sf::RenderTarget& target)
{
	target.draw(this->winningText);
	target.draw(this->playAgainButton);
	target.draw(this->playAgainText);
	target.draw(this->menuButton);
	target.draw(this->menuText);
}

void HandWonUI::update()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

	this->processPlayerChoices();


}


void HandWonUI::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	
	this->renderGameObjects(*this->window);


	this->window->display();
}

HandWonUI::HandWonUI()
{
	this->initVariables();
	this->initialiseWindow();
	this->initHandWonText();
	this->initHandWonButtons();
}

HandWonUI::~HandWonUI()
{
}
