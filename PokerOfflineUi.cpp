#include "PokerOfflineUi.h"
#include "Poker.h"
#include <thread>
#include <iostream>
#include "ObserverPattern.cpp"
#include "utils.hpp"

void PokerOfflineUi::initialiseVariables()
{
	this->window = nullptr;
	this->potAmount = 0;
	this->lMBDown = false;
	this->hasStarted=false;
	this->deck.initialiseDeck();	

	

}
void PokerOfflineUi::launchPoker()
{
	Poker poker;
	this->pokerGame = &poker;
	poker.attach(this);
}

void PokerOfflineUi::initialiseWindow() 
{
	this->videomode.height = 1080;
	this->videomode.width = 1920;
	/*this->videomode.getDesktopMode;*/
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}
void PokerOfflineUi::initialiseMenuBar()
{
	this->font.loadFromFile("Fonts/Roboto-Black.ttf");
	// Create Menu Bar
	this->menuBar.setPosition(0, 0);
	this->menuBar.setSize(sf::Vector2f(this->videomode.width, 100.f));
	this->menuBar.setFillColor(sf::Color::Black);

	//Title Text
	this->title.setString("Poker & Probability");
	this->title.setFillColor(sf::Color::White);
	this->title.setFont(font);
	this->title.setCharacterSize(int(this->videomode.width / 25));
	sf::FloatRect titleRectangle = this->title.getLocalBounds();
	this->title.setOrigin(titleRectangle.left + round(titleRectangle.width / 2.0f), titleRectangle.top + round(titleRectangle.height / 2.0f));
	this->title.setPosition(this->videomode.width / 2, 50.f);

	// Settings Text
	this->settings.setString("Settings");
	this->settings.setFillColor(sf::Color::White);
	this->settings.setFont(font);
	this->settings.setCharacterSize(int(this->videomode.width / 35));
	sf::FloatRect settingsRectangle = this->settings.getLocalBounds();
	this->settings.setOrigin(settingsRectangle.left + round(settingsRectangle.width / 2.0f), settingsRectangle.top + round(settingsRectangle.height / 2.0f));
	this->settings.setPosition(this->videomode.width/2 - this->videomode.width / 3, 50.f);

	// Instructions Text
	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setFont(font);
	this->instructions.setCharacterSize(int(this->videomode.width / 35));
	sf::FloatRect instructionsRectangle = this->instructions.getLocalBounds();
	this->instructions.setOrigin(instructionsRectangle.left + round(instructionsRectangle.width / 2.0f), instructionsRectangle.top + round(instructionsRectangle.height / 2.0f));
	this->instructions.setPosition(this->videomode.width / 2 + this->videomode.width/3, 50.f);


}

void PokerOfflineUi::initialisePlayScreenObjects()
{
	this->initialiseCommunityCardSprites();
	this->initialisePlayerCardsSprites();
	this->initialiseGeneralPlayButtons();
}

void PokerOfflineUi::initialiseCommunityCardSprites()
{
	this->communityCard1.setTexture(this->deck.backOfCardTexture);
	this->communityCard1.setScale(1.5f, 1.5f);
	sf::FloatRect cardRectangle = this->communityCard1.getLocalBounds();
	this->communityCard1.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->communityCard1.setPosition((this->videomode.width / 2) - 2*(this->videomode.width / 20), 270.f);

	this->communityCard2.setTexture(this->deck.backOfCardTexture);
	this->communityCard2.setScale(1.5f, 1.5f);
	cardRectangle = this->communityCard1.getLocalBounds();
	this->communityCard2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->communityCard2.setPosition((this->videomode.width / 2) - (this->videomode.width / 20), 270.f);

	this->communityCard3.setTexture(this->deck.backOfCardTexture);
	this->communityCard3.setScale(1.5f, 1.5f);
	cardRectangle = this->communityCard3.getLocalBounds();
	this->communityCard3.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->communityCard3.setPosition((this->videomode.width / 2) , 270.f);

	this->communityCard4.setTexture(this->deck.backOfCardTexture);
	this->communityCard4.setScale(1.5f, 1.5f);
	cardRectangle = this->communityCard1.getLocalBounds();
	this->communityCard4.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->communityCard4.setPosition((this->videomode.width / 2) + (this->videomode.width / 20), 270.f);

	this->communityCard5.setTexture(this->deck.backOfCardTexture);
	this->communityCard5.setScale(1.5f, 1.5f);
	cardRectangle = this->communityCard1.getLocalBounds();
	this->communityCard5.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->communityCard5.setPosition((this->videomode.width / 2) + 2*(this->videomode.width / 20), 270.f);

}

void PokerOfflineUi::initialisePlayerCardsSprites()
{
	this->player1card1.setTexture(this->deck.backOfCardTexture);
	this->player1card1.setScale(1.5f, 1.5f);
	sf::FloatRect cardRectangle = this->player1card1.getLocalBounds();
	this->player1card1.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player1card1.setPosition((this->videomode.width / 2) - (this->videomode.width / 30), 900.f);

	this->player1card2.setTexture(this->deck.backOfCardTexture);
	this->player1card2.setScale(1.5f, 1.5f);
	this->player1card2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player1card2.setPosition((this->videomode.width / 2) + (this->videomode.width / 30), 900.f);

	this->player2card1.setTexture(this->deck.backOfCardTexture);
	this->player2card1.setRotation(90.f);
	this->player2card1.setScale(1.5f, 1.5f);
	this->player2card1.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player2card1.setPosition(this->videomode.width / 30, 600.f);

	this->player2card2.setTexture(this->deck.backOfCardTexture);
	this->player2card2.setScale(1.5f, 1.5f);
	this->player2card2.setRotation(90.f);
	this->player2card2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player2card2.setPosition(this->videomode.width / 30, 520.f);


	this->player3card1.setTexture(this->deck.backOfCardTexture);
	this->player3card1.setScale(1.5f, 1.5f);
	this->player3card1.setRotation(90.f);
	this->player3card1.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player3card1.setPosition(this->videomode.width / 30, 400.f);

	this->player3card2.setTexture(this->deck.backOfCardTexture);
	this->player3card2.setScale(1.5f, 1.5f);
	this->player3card2.setRotation(90.f);
	this->player3card2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player3card2.setPosition(this->videomode.width / 30, 320.f);

	this->player4card1.setTexture(this->deck.backOfCardTexture);
	this->player4card1.setScale(1.5f, 1.5f);
	this->player4card1.setRotation(270.f);
	this->player4card1.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player4card1.setPosition(this->videomode.width - this->videomode.width / 30, 600.f);

	this->player4card2.setTexture(this->deck.backOfCardTexture);
	this->player4card2.setScale(1.5f, 1.5f);
	this->player4card2.setRotation(270.f);
	this->player4card2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player4card2.setPosition(this->videomode.width - this->videomode.width / 30, 520.f);

}

void PokerOfflineUi::initialiseGeneralPlayButtons()
{
	this->pokerHandsButton.setFillColor(sf::Color::Red);
	this->pokerHandsButton.setSize(sf::Vector2f(this->videomode.width/12, this->videomode.height/20));
	sf::FloatRect pokerHandsRectangle = this->pokerHandsButton.getLocalBounds();
	this->pokerHandsButton.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->pokerHandsButton.setPosition(1750.f, 250.f);


	this->pokerHandsText.setString("Poker Hands");
	this->pokerHandsText.setFillColor(sf::Color::White);
	this->pokerHandsText.setFont(font);
	this->pokerHandsText.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->pokerHandsText.getLocalBounds();
	this->pokerHandsText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->pokerHandsText.setPosition(this->pokerHandsButton.getPosition());

}

//Overriding observer functions
void PokerOfflineUi::startGame()
{
	
	this->gameStateText.setString("Starting game");
	
	this->gameStateText.setString("3");
	this->render();
	delay(1000);
	this->gameStateText.setString("2");
	this->render();
	delay(1000);
	this->gameStateText.setString("1");
	this->render();
	delay(1000);

	this->gameStateRect.setFillColor(sf::Color::Transparent);
	this->gameStateText.setFillColor(sf::Color::Transparent);
	
	delay(1000);
	this->gameStateText.setFillColor(sf::Color::Black);
	this->gameStateText.setString("Hand being dealt");
	this->hasStarted = true;
	this->pokerGame->startGame();
}
void PokerOfflineUi::endGame()
{

}
void PokerOfflineUi::updateOnBet()
{

}
void PokerOfflineUi::updateCommunityCards()
{

}
void PokerOfflineUi::updatePlayerCards()
{

}


void PokerOfflineUi::initialisePlayerButtons()
{
}

void PokerOfflineUi::initialiseGameStateButton()
{
	//start game rectangle
	this->gameStateRect.setFillColor(sf::Color::Red);
	this->gameStateRect.setSize(sf::Vector2f(this->videomode.width/12, this->videomode.height/20));
	sf::FloatRect pokerHandsRectangle = this->gameStateRect.getLocalBounds();
	this->gameStateRect.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->gameStateRect.setPosition(this->videomode.width/2, this->videomode.height/2);

	//Start game Text
	this->gameStateText.setString("Start Game");
	this->gameStateText.setFillColor(sf::Color::White);
	this->gameStateText.setFont(font);
	this->gameStateText.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->gameStateText.getLocalBounds();
	this->gameStateText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->gameStateText.setPosition(this->gameStateRect.getPosition());
}

void PokerOfflineUi::renderText(sf::RenderTarget& target)
{
	target.draw(this->title);
	target.draw(this->settings);
	target.draw(this->instructions);
	target.draw(this->pokerHandsText);
	target.draw(this->gameStateText);
}

void PokerOfflineUi::renderGameObjects(sf::RenderTarget& target)
{
	target.draw(this->communityCard1);
	target.draw(this->communityCard2);
	target.draw(this->communityCard3);
	target.draw(this->communityCard4);
	target.draw(this->communityCard5);
	target.draw(this->player1card1);
	target.draw(this->player1card2);
	target.draw(this->player2card1);
	target.draw(this->player2card2);
	target.draw(this->player3card1);
	target.draw(this->player3card2);
	target.draw(this->player4card1);
	target.draw(this->player4card2);
	target.draw(this->pokerHandsButton);
	target.draw(this->gameStateRect);

}
void PokerOfflineUi::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	this->window->draw(this->menuBar);

	this->renderGameObjects(*this->window);

	this->renderText(*this->window);

	this->window->display();

}


const bool PokerOfflineUi::isGameRunning() const
{
	return this->window->isOpen();
}

void PokerOfflineUi::processStartingClick(){
	//check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	{
		if (!this->lMBDown) 
		{
			this->lMBDown = true;
			if (this->gameStateRect.getGlobalBounds().contains(this->mousePositionFloat))
			{
				this->startGame();
				
			}
			
		}
		
		
	}
	else
	{
		this->lMBDown = false;
	}
}


void PokerOfflineUi::pollEvents() 
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

//Constructor and Destructor
PokerOfflineUi::PokerOfflineUi()
{
	this->initialiseVariables();
	this->initialiseWindow();
	this->initialiseMenuBar();
	this->initialiseGameStateButton();
	this->initialisePlayScreenObjects();
	this->launchPoker();
	// this->t1 = std::thread(&PokerOfflineUi::launchPoker, this);
	// std::cout<<"UI"<<std::endl;
	// this->t1.join();

}

PokerOfflineUi::~PokerOfflineUi()
{
	delete this->window;
}


void PokerOfflineUi::updateMousePositions()
{
	this->mousePositionInt = sf::Mouse::getPosition(*this->window);
	this->mousePositionFloat = this->window->mapPixelToCoords(this->mousePositionInt);
}
void PokerOfflineUi::initialUpdate(){
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	
	this->processStartingClick();

	
}
	
void PokerOfflineUi::update() {


	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	


	
}
