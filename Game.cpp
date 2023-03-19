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
	this->videomode.height = 720;
	this->videomode.width = 1280;
	/*this->videomode.getDesktopMode;*/
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(30);
}

void Game::initialiseMenuBar()
{
	// Create Menu Bar
	this->menuBar.setPosition(0, 0);
	this->menuBar.setSize(sf::Vector2f(this->videomode.width, 100.f));
	this->menuBar.setFillColor(sf::Color::Black);

	//Title Text
	this->title.setString("Poker & Probability");
	this->title.setFillColor(sf::Color::White);
	this->title.setFont(font);
	this->title.setCharacterSize(50);
	sf::FloatRect titleRectangle = this->title.getLocalBounds();

	this->title.setOrigin(titleRectangle.left + round(titleRectangle.width / 2.0f), titleRectangle.top + round(titleRectangle.height / 2.0f));
	this->title.setPosition(this->videomode.width / 2, 50.f);


}

void Game::initialiseMenuScreen()
{
	//add Text for Play vs AI, Settings, How to Use, Instructions

	this->font.loadFromFile("Fonts/Roboto-Black.ttf");

	//Add menuBar
	this->initialiseMenuBar();

	//add playing card sprites
	
	this->initialisePlayingCards();
	


	// Menu choices

	//Play vs computer
	this->playVsAi.setString("Play vs Computer");
	this->playVsAi.setFillColor(sf::Color::White);
	this->playVsAi.setFont(font);
	this->playVsAi.setCharacterSize(30);
	sf::FloatRect playVsAiRectangle = this->playVsAi.getLocalBounds();
	this->playVsAi.setOrigin(playVsAiRectangle.left + round(playVsAiRectangle.width / 2.0f), playVsAiRectangle.top + round(playVsAiRectangle.height / 2.0f));
	this->playVsAi.setPosition(this->videomode.width / 2, 300.f);

	//settings item

	this->settings.setString("Settings");
	this->settings.setFillColor(sf::Color::White);
	this->settings.setFont(font);
	this->settings.setCharacterSize(30);
	sf::FloatRect settingsRectangle = this->settings.getLocalBounds();
	this->settings.setOrigin(settingsRectangle.left + round(settingsRectangle.width / 2.0f), settingsRectangle.top + round(settingsRectangle.height / 2.0f));
	this->settings.setPosition(this->videomode.width / 2, 400.f);

	// how to play choice
	
	this->howToPlay.setString("How To Play");
	this->howToPlay.setFillColor(sf::Color::White);
	this->howToPlay.setFont(font);
	this->howToPlay.setCharacterSize(30);
	sf::FloatRect howToPlayRectangle = this->howToPlay.getLocalBounds();
	
	this->howToPlay.setOrigin(howToPlayRectangle.left + round(howToPlayRectangle.width / 2.0f), howToPlayRectangle.top + round(howToPlayRectangle.height / 2.0f));
	this->howToPlay.setPosition(round(this->videomode.width / 2), 500.f);

	

	//instructions choice
	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setFont(font);
	this->instructions.setCharacterSize(30);
	sf::FloatRect instructionsRectangle = this->instructions.getLocalBounds();
	this->instructions.setOrigin(instructionsRectangle.left + round(instructionsRectangle.width / 2.0f), instructionsRectangle.top + round(instructionsRectangle.height / 2.0f));
	this->instructions.setPosition(this->videomode.width / 2, 600.f);

	

}

void Game::initialisePlayingCards()
{
	//Loading textures
	this->heartsTen.loadFromFile("Resources/card_hearts_10.png");
	this->heartsJack.loadFromFile("Resources/card_hearts_J.png");
	this->heartsQueen.loadFromFile("Resources/card_hearts_Q.png");
	this->heartsKing.loadFromFile("Resources/card_hearts_K.png");
	this->heartsAce.loadFromFile("Resources/card_hearts_A.png");

	// Setting sprites textures
	this->ten.setTexture(this->heartsTen);
	sf::FloatRect tenRectangle = this->ten.getLocalBounds();
	this->ten.setOrigin(tenRectangle.left + round(tenRectangle.width / 2.0f), tenRectangle.top + round(tenRectangle.height / 2.0f));
	this->ten.setPosition((this->videomode.width / 2)-200, 200.f);

	this->jack.setTexture(this->heartsJack);
	sf::FloatRect jackRectangle = this->jack.getLocalBounds();
	this->jack.setOrigin(jackRectangle.left + round(jackRectangle.width / 2.0f), jackRectangle.top + round(jackRectangle.height / 2.0f));
	this->jack.setPosition((this->videomode.width / 2)-100, 200.f);

	this->queen.setTexture(this->heartsQueen);
	sf::FloatRect queenRectangle = this->queen.getLocalBounds();
	this->queen.setOrigin(queenRectangle.left + round(queenRectangle.width / 2.0f), queenRectangle.top + round(queenRectangle.height / 2.0f));
	this->queen.setPosition(this->videomode.width / 2, 200.f);
	

	this->king.setTexture(this->heartsKing);
	sf::FloatRect kingRectangle = this->king.getLocalBounds();
	this->king.setOrigin(kingRectangle.left + round(kingRectangle.width / 2.0f), kingRectangle.top + round(kingRectangle.height / 2.0f));
	this->king.setPosition((this->videomode.width / 2)+100, 200.f);

	this->ace.setTexture(this->heartsAce);
	sf::FloatRect aceRectangle = this->ace.getLocalBounds();
	this->ace.setOrigin(aceRectangle.left + round(aceRectangle.width / 2.0f), aceRectangle.top + round(aceRectangle.height / 2.0f));
	this->ace.setPosition((this->videomode.width / 2 )+200, 200.f);

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

void Game::renderMenuSprites(sf::RenderTarget& target)
{
	target.draw(this->ten);
	target.draw(this->jack);
	target.draw(this->queen);
	target.draw(this->king);
	target.draw(this->ace);
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

	this->renderMenuSprites(*this->window);
	
	

	

	this->window->display();
}


