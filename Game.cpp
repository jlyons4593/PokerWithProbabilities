#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>



//Private Functions
void Game::initialiseVariables()
{
	this->window = nullptr;

	this->lMBDown = false;

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
	// Create Menu Bar
	this->menuBar.setPosition(0, 0);
	this->menuBar.setSize(sf::Vector2f(800.f, 100.f));
	this->menuBar.setFillColor(sf::Color::Black);

	//Title Text
	this->title.setString("Poker & Probability");
	this->title.setFillColor(sf::Color::White);
	this->title.setFont(font);
	this->title.setCharacterSize(50);
	sf::FloatRect titleRectangle = this->title.getLocalBounds();

	this->title.setOrigin(titleRectangle.left + titleRectangle.width / 2.0f, titleRectangle.top + titleRectangle.height / 2.0f);
	this->title.setPosition(this->videomode.width / 2, 50.f);


}

void Game::initialiseMenuScreen()
{
	//add Text for Play vs AI, Settings, How to Use, Instructions

	this->font.loadFromFile("Fonts/Roboto-Black.ttf");

	//Add menuBar
	this->initialiseMenuBar();


	// Menu choices

	// how to play choice
	
	this->howToPlay.setString("How To Play");
	this->howToPlay.setFillColor(sf::Color::White);
	this->howToPlay.setFont(font);
	this->howToPlay.setCharacterSize(30);
	sf::FloatRect howToPlayRectangle = this->howToPlay.getLocalBounds();

	this->howToPlay.setOrigin(howToPlayRectangle.left + howToPlayRectangle.width / 2.0f, howToPlayRectangle.top + howToPlayRectangle.height / 2.0f);
	this->howToPlay.setPosition(this->videomode.width / 2, 150.f);

	//settings item
	
	this->settings.setString("Settings");
	this->settings.setFillColor(sf::Color::White);
	this->settings.setFont(font);
	this->settings.setCharacterSize(30);
	sf::FloatRect settingsRectangle = this->settings.getLocalBounds();
	this->settings.setOrigin(settingsRectangle.left + settingsRectangle.width / 2.0f, settingsRectangle.top + settingsRectangle.height / 2.0f);
	this->settings.setPosition(this->videomode.width/2, 225.f);

	//instructions choice
	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setFont(font);
	this->instructions.setCharacterSize(30);
	sf::FloatRect instructionsRectangle = this->instructions.getLocalBounds();
	this->instructions.setOrigin(instructionsRectangle.left + instructionsRectangle.width / 2.0f, instructionsRectangle.top + instructionsRectangle.height / 2.0f);
	this->instructions.setPosition(this->videomode.width / 2, 300.f);

	this->playVsAi.setString("Play VS AI");
	this->playVsAi.setFillColor(sf::Color::White);
	this->playVsAi.setFont(font);
	this->playVsAi.setCharacterSize(30);
	sf::FloatRect playVsAiRectangle = this->playVsAi.getLocalBounds();
	this->playVsAi.setOrigin(playVsAiRectangle.left + playVsAiRectangle.width / 2.0f, playVsAiRectangle.top + playVsAiRectangle.height / 2.0f);
	this->playVsAi.setPosition(this->videomode.width / 2, 375.f);

}




//Constructor and Destructor
Game::Game()
{
	this->initialiseVariables();
	this->initialiseWindow();
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
	target.draw(this->howToPlay);
	target.draw(this->instructions);
	target.draw(this->playVsAi);
	target.draw(this->settings);
	target.draw(this->title);
}

void Game::processMenuChoices()
{
	if (this->howToPlay.getGlobalBounds().contains(this->mousePositionFloat))
	{
		std::cout << "User chose how to play" << std::endl;

	}
	else if (this->settings.getGlobalBounds().contains(this->mousePositionFloat))
	{
		std::cout << "User chose Settings" << std::endl;
	}
	else if (this->instructions.getGlobalBounds().contains(this->mousePositionFloat))
	{
		std::cout << "User chose instructions" << std::endl;
	}
	else if (this->playVsAi.getGlobalBounds().contains(this->mousePositionFloat))
	{
		std::cout << "User chose play vs AI" << std::endl;
	}
}

void Game::updateMousePositions()
{
	this->mousePositionInt = sf::Mouse::getPosition(*this->window);
	this->mousePositionFloat = this->window->mapPixelToCoords(this->mousePositionInt);
}

void Game::update()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

	this->UpdateText();
}

void Game::UpdateText()
{
	//check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	{
		if (!this->lMBDown) 
		{
			this->lMBDown = true;
			this->processMenuChoices();
		}
		
		
	}
	else
	{
		this->lMBDown = false;
	}
	

}

void Game::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	//draw menu
	this->window->draw(this->menuBar);
	
	this->renderMenuText(*this->window);
	
	

	

	this->window->display();
}


