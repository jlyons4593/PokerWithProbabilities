#include "Game.h"

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
	sf::Font font;
	font.loadFromFile("");
	this->howToUse.setPosition(300, 250);
	this->howToUse.setCharacterSize(25);
	this->howToUse.setString("How To Use");
	this->howToUse.setFillColor(sf::Color::White);
	this->settings.setString("Settings");
	this->settings.setFillColor(sf::Color::White);
	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->playVsAi.setString("Play VS AI");
	this->playVsAi.setFillColor(sf::Color::White);
	




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
void Game::update()
{
	this->pollEvents();

	//get mouse pos
	std::cout << "Mouse pos = " << sf::Mouse::getPosition(*this->window).x << "," << sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	//draw menu
	this->window->draw(this->menuBar);
	this->window->draw(this->playVsAi);
	this->window->draw(this->howToUse);
	this->window->draw(this->instructions);
	this->window->draw(this->settings);


	

	this->window->display();
}
