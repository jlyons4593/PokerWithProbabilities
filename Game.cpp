#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>



//Private Functions
void Game::initialiseVariables()
{
	this->window = nullptr;

}

void Game::initialiseWindow()
{
	this->videomode.height = 600;
	this->videomode.width = 800;
	/*this->videomode.getDesktopMode;*/
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(30);
}

void Game::initialiseMenuBar()
{
	this->menuBar.setPosition(0, 0);
	this->menuBar.setSize(sf::Vector2f(800.f, 100.f));
	this->menuBar.setFillColor(sf::Color::Black);



}

void Game::initialiseMenuScreen()
{
	//add Text for Play vs AI, Settings, How to Use, Instructions

	this->font.loadFromFile("Fonts/Roboto-Black.ttf");

	this->howToUse.setString("How To Play");
	this->howToUse.setFillColor(sf::Color::White);
	this->howToUse.setFont(font);
	this->howToUse.setCharacterSize(30);
	
	/*this->settings.setString("Settings");
	this->settings.setFillColor(sf::Color::White);
	this->settings.setFont(font);
	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setFont(font);*/
	/*this->playVsAi.setString("Play VS AI");
	this->playVsAi.setFillColor(sf::Color::White);
	this->playVsAi.setFont(font);
	*/




}



//Constructor and Destructor
Game::Game()
{
	this->initialiseVariables();
	this->initialiseWindow();
	this->initialiseMenuBar();
	this->initialiseMenuScreen();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::isGameRunning() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}

	}
}

//Functions

void Game::renderMenuText(sf::RenderTarget& target)
{
	target.draw(this->howToUse);
}

void Game::update()
{
	this->pollEvents();

	//get mouse pos
	std::cout << "Mouse pos = " << sf::Mouse::getPosition(*this->window).x << "," << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::UpdateText()
{
}

void Game::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	//draw menu
	this->window->draw(this->menuBar);
	
	this->renderMenuText(*this->window);
	
	

	

	this->window->display();
}


