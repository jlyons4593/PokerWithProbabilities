#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include "deck.h"
#include "PokerOfflineUi.h"



//Private Functions
void Game::initialiseVariables()
{
	this->window = nullptr;
	
	this->lMBDown = false;

	this->deckLoader();

}

void Game::deckLoader() {
	// Creating deck instance
	
	this->deck.initialiseDeck();

	/*Card c = this->deck.drawCard();
	Card b = this->deck.drawCard();
	std::cout << (int)c.value << " of " << (int)c.suit << std::endl;
	std::cout << int(b.value) << " of " << (int)b.suit << std::endl;
	this->deck.shuffleDeck();
	Card d = this->deck.drawCard();
	std::cout << (int)d.value << " of " << (int)d.suit << std::endl;*/
}

void Game::initialiseWindow()
{
	this->videomode.height = 762;
	this->videomode.width = 1280;
	/*this->videomode.getDesktopMode;*/
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
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
	this->title.setCharacterSize(int(this->videomode.width/25));
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
	this->playVsAi.setCharacterSize(int(videomode.width/30));
	sf::FloatRect playVsAiRectangle = this->playVsAi.getLocalBounds();
	this->playVsAi.setOrigin(playVsAiRectangle.left + round(playVsAiRectangle.width / 2.0f), playVsAiRectangle.top + round(playVsAiRectangle.height / 2.0f));
	this->playVsAi.setPosition(this->videomode.width / 2, 200 + this->videomode.height / 8);

	//settings item

	this->settings.setString("Settings");
	this->settings.setFillColor(sf::Color::White);
	this->settings.setFont(font);
	this->settings.setCharacterSize(int(videomode.width/30)); 
	sf::FloatRect settingsRectangle = this->settings.getLocalBounds();
	this->settings.setOrigin(settingsRectangle.left + round(settingsRectangle.width / 2.0f), settingsRectangle.top + round(settingsRectangle.height / 2.0f));
	this->settings.setPosition(this->videomode.width / 2, 200 + 2*(this->videomode.height / 8));

	// how to play choice
	
	this->howToPlay.setString("How To Play");
	this->howToPlay.setFillColor(sf::Color::White);
	this->howToPlay.setFont(font);
	this->howToPlay.setCharacterSize(int(videomode.width/30));
	sf::FloatRect howToPlayRectangle = this->howToPlay.getLocalBounds();
	
	this->howToPlay.setOrigin(howToPlayRectangle.left + round(howToPlayRectangle.width / 2.0f), howToPlayRectangle.top + round(howToPlayRectangle.height / 2.0f));
	this->howToPlay.setPosition(round(this->videomode.width / 2), 200+3*(this->videomode.height / 8));

	
	//instructions choice

	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setFont(font);
	this->instructions.setCharacterSize(int(videomode.width/30));
	sf::FloatRect instructionsRectangle = this->instructions.getLocalBounds();
	this->instructions.setOrigin(instructionsRectangle.left + round(instructionsRectangle.width / 2.0f), instructionsRectangle.top + round(instructionsRectangle.height / 2.0f));
	this->instructions.setPosition(this->videomode.width / 2, 200 + 4*(this->videomode.height / 8));

	

}

void Game::initialisePlayingCards()
{

	// Setting sprites textures
	this->ten.setTexture(this->deck.currentDeck[35].cardFace);
	this->ten.setScale(1.8f,1.8f);
	sf::FloatRect tenRectangle = this->ten.getLocalBounds();
	this->ten.setOrigin(tenRectangle.left + round(tenRectangle.width / 2.0f), tenRectangle.top + round(tenRectangle.height / 2.0f));
	this->ten.setPosition((this->videomode.width / 2)-(this->videomode.width/5), 200.f);
	

	this->jack.setTexture(this->deck.currentDeck[36].cardFace);
	this->jack.setScale(1.8f,1.8f);
	sf::FloatRect jackRectangle = this->jack.getLocalBounds();
	this->jack.setOrigin(jackRectangle.left + round(jackRectangle.width / 2.0f), jackRectangle.top + round(jackRectangle.height / 2.0f));
	this->jack.setPosition((this->videomode.width / 2)-(this->videomode.width/10), 200.f);

	this->queen.setTexture(this->deck.currentDeck[37].cardFace);
	this->queen.setScale(1.8f,1.8f);
	sf::FloatRect queenRectangle = this->queen.getLocalBounds();
	this->queen.setOrigin(queenRectangle.left + round(queenRectangle.width / 2.0f), queenRectangle.top + round(queenRectangle.height / 2.0f));
	this->queen.setPosition(this->videomode.width / 2, 200.f);
	

	this->king.setTexture(this->deck.currentDeck[38].cardFace);
	this->king.setScale(1.8f,1.8f);
	sf::FloatRect kingRectangle = this->king.getLocalBounds();
	this->king.setOrigin(kingRectangle.left + round(kingRectangle.width / 2.0f), kingRectangle.top + round(kingRectangle.height / 2.0f));
	this->king.setPosition((this->videomode.width / 2)+(this->videomode.width/10), 200.f);

	this->ace.setTexture(this->deck.currentDeck[36].cardFace);
	this->ace.setScale(1.8f,1.8f);
	sf::FloatRect aceRectangle = this->ace.getLocalBounds();
	this->ace.setOrigin(aceRectangle.left + round(aceRectangle.width / 2.0f), aceRectangle.top + round(aceRectangle.height / 2.0f));
	this->ace.setPosition((this->videomode.width / 2 )+(this->videomode.width/5), 200.f);

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
		PokerOfflineUi newGame;
		this->window->close();
		
		while (newGame.isGameRunning())
		{
			//Update
			newGame.update();

			//Render
			newGame.render();
		}

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


