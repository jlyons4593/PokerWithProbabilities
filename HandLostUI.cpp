#include "HandLostUI.h"


void HandLostUI::initVariables()
{
	this->isGameRunning = true;
	this->font.loadFromFile("Fonts/Roboto-Black.ttf");
}
void HandLostUI::initialiseWindow()
{
	this->videomode.height = 720;
	this->videomode.width = 1280;

	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void HandLostUI::initHandLostText()
{
	std::string string = "   Unlucky you Lose!!\nDo you want to play again?";

	this->setTextProperties(this->winningText, string, sf::Vector2f(this->videomode.width / 2, this->videomode.height / 2 - 150), int(this->videomode.width / 50), sf::Color::Black);
}

void HandLostUI::initHandLostButtons()
{
	// Menu
	this->setRectangleProperties(this->menuButton, sf::Vector2f(this->videomode.width / 10, this->videomode.height / 15), sf::Vector2f(this->videomode.width / 2 , 400.f), sf::Color::Black);
	this->setTextProperties(this->menuText, "Menu", sf::Vector2f(this->menuButton.getPosition()), int(this->videomode.width / 80), sf::Color::White);

	//Play again
	//this->setRectangleProperties(this->playAgainButton, sf::Vector2f(this->videomode.width / 10, this->videomode.height / 15), sf::Vector2f(this->videomode.width / 2 + 100, 400.f), sf::Color::Black);
	//this->setTextProperties(this->playAgainText, "Play Again!", sf::Vector2f(this->playAgainButton.getPosition()), int(this->videomode.width / 80), sf::Color::White);
}

void HandLostUI::processPlayerChoices()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->lMBDown)
		{
			this->lMBDown = true;
			if (this->menuButton.getGlobalBounds().contains(this->mousePositionFloat))
			{
				this->startMenu();
			}
		}
	}
	else
	{
		this->lMBDown = false;
	}
}

void HandLostUI::renderGameObjects(sf::RenderTarget& target)
{
	target.draw(this->winningText);
	target.draw(this->playAgainButton);
	target.draw(this->playAgainText);
	target.draw(this->menuButton);
	target.draw(this->menuText);
}

void HandLostUI::startMenu()
{
	Game game;
	this->window->close();
	while (game.isGameRunning())
	{
		//Update
		game.update();

		//Render
		game.render();
	}
}

void HandLostUI::update()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

	this->processPlayerChoices();


}


void HandLostUI::render()
{
	this->window->clear(sf::Color(0, 100, 0));


	this->renderGameObjects(*this->window);


	this->window->display();
}

HandLostUI::HandLostUI()
{
	this->initVariables();
	this->initialiseWindow();
	this->initHandLostText();
	this->initHandLostButtons();
}

HandLostUI::~HandLostUI()
{
}
