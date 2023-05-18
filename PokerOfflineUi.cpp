#include "PokerOfflineUi.h"
#include "Poker.h"
#include <thread>
#include <iostream>
#include "ObserverPattern.cpp"
#include "Delay.hpp"
#include "PokerHandsUI.h"
#include "AudioManager.cpp"
#include "HandWonUI.h"
#include "HandLostUI.h"





void PokerOfflineUi::initialiseVariables()
{
	this->window = nullptr;
	this->potAmount = 0;
	this->lMBDown = false;
	this->hasStarted=false;
	this->readyUp = false;
	this->raiseBoxActive = false;
	this->keyDown = false;
	this->chipsRaisedInt=0;
	this->playerBetAmount = 0;
	this->potAmount = 0;
	this->hasFolded = false;
	this->isLookingAtHands = true;
	this->isPokerHandsOpen = false;
	this->isOddsViewOpen = false;
	this->inOddsViewHelp = false;
	this->inInstruction = false;

}
void PokerOfflineUi::launchPoker()
{

	this->pokerGame = new Poker();
	this->pokerGame->attach(this);
	this->pokerGame->setChips(this->chipsPerPlayer);
	this->setPlayerChips(this->pokerGame->chipsPerPlayer);

	if (this->isPractice) {
		this->oddsView_ = new OddsView();
		this->pokerGame->attach(this->oddsView_);
	}
	

	
}

void PokerOfflineUi::launchOddsView() {
	
}
void PokerOfflineUi::setWaitingStatuses()
{
	AIStatus.setString("Waiting");
	AI2Status.setString("Waiting");
	AI3Status.setString("Waiting");
	this->render();

}
void PokerOfflineUi::initialiseInstructions()
{
	std::string title = "Instructions";
	this->setTextProperties(this->instructionTitle, title, sf::Vector2f(this->videomode.width / 2, this->videomode.height / 2 - 350), int(videomode.width / 40), sf::Color::White);
	std::string text = "Look at your hand and the cards in the middle by combinig the 2 sets of cards you want to see how\ngood your hand is and bet accordingly.\nIf you do not know how the card ranking system works click on the Poker Hands button to provide\nyou more information.\nUse the Bet increment and decrementer buttons to choose how much you wish to bet. Once you \nhave settled on a number click confirm and ready up.\nIf you confirm with 0 as your bet amount and ready up you will check or call depending on whether \nthere is a bet to match.\nYou can also click the fold button and confirm to allow you to not play the hand. \nWin the hand to unlock achievements.";
	this->setTextProperties(this->instructionText, text, sf::Vector2f(50, this->videomode.height / 2 - 300), int(videomode.width / 50), sf::Color::White);
	this->instructionText.setOrigin(0, 0);
	this->setTextProperties(this->backText, "Back", sf::Vector2f(50, 50), int(videomode.width / 50), sf::Color::White);
	this->setRectangleProperties(this->backButton, sf::Vector2f(70.f, 80.f), sf::Vector2f(50, 50), sf::Color::Black);

	title = "Odds View Help";
	text = "Click on the odds view button in the top right to view your odds!\n\n1. The Pot odds is the percentage of time you will need to win the hand to break even when you call \nfor $10 \n\n2. The expected value  is a measure of the average amount of money you can expect to win or lose\nover the long run when betting $20. It takes into account the probability of different outcomes \nand their payoffs.\n\n3. Hand strength is an estimate of the percentage of hands that beat your hand. \n\n4. Outs is the number of cards left in the deck that would improve your hand";
	this->setTextProperties(this->oddsInstructionTitle, title, sf::Vector2f(this->videomode.width / 2, this->videomode.height / 2 - 350), int(videomode.width / 40), sf::Color::White);
	this->setTextProperties(this->oddsInstructionText, text, sf::Vector2f(50, this->videomode.height / 2 - 300), int(videomode.width / 50), sf::Color::White);
	this->oddsInstructionText.setOrigin(0, 0);

}
void PokerOfflineUi::updateInstruction()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	this->handleInstructionUpdate();
}
void PokerOfflineUi::renderInstruction()
{
	this->window->clear(sf::Color(0, 100, 0));



	//draw menu
	this->window->draw(this->menuBar);
	this->window->draw(this->title);
	this->window->draw(this->instructionTitle);

	this->window->draw(this->instructionText);
	this->window->draw(this->backButton);
	this->window->draw(this->backText);




	this->window->display();
}
void PokerOfflineUi::handleInstructionUpdate()
{
	//check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->backButton.getGlobalBounds().contains(this->mousePositionFloat))
		{
			if (!this->lMBDown)
			{
				AudioManager::getInstance().playMenuNoise();
				this->lMBDown = true;
				
				this->inInstruction = false;
				this->inOddsViewHelp = false;
			}
		}

	}
	else
	{
		this->lMBDown = false;
	}
}
void PokerOfflineUi::updateOddsViewHelp()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	this->handleInstructionUpdate();
}
void PokerOfflineUi::renderOddsViewHelp()
{
	this->window->clear(sf::Color(0, 100, 0));



	//draw menu
	this->window->draw(this->menuBar);
	this->window->draw(this->title);
	this->window->draw(this->oddsInstructionTitle);

	this->window->draw(this->oddsInstructionText);
	this->window->draw(this->backButton);
	this->window->draw(this->backText);




	this->window->display();
}
void PokerOfflineUi::setPlayerChips(int chips){
	this->playerChipsInt = chips;
	this->AIChipsInt = chips;
	this->AI2ChipsInt = chips;
	this->AI3ChipsInt = chips;
	this->AI4ChipsInt = chips;
	

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


	// Instructions Text
	this->instructions.setString("Instructions");
	this->instructions.setFillColor(sf::Color::White);
	this->instructions.setFont(font);
	this->instructions.setCharacterSize(int(this->videomode.width / 35));
	sf::FloatRect instructionsRectangle = this->instructions.getLocalBounds();
	this->instructions.setOrigin(instructionsRectangle.left + round(instructionsRectangle.width / 2.0f), instructionsRectangle.top + round(instructionsRectangle.height / 2.0f));
	this->instructions.setPosition(this->videomode.width / 2 + this->videomode.width/3, 50.f);


	if (this->isPractice) {
		this->setTextProperties(this->oddsViewInstructions, "Odds View Help", sf::Vector2f(this->videomode.width / 2 - this->videomode.width / 3, 50.f), int(this->videomode.width / 35), sf::Color::White);
	}

}

void PokerOfflineUi::initialisePlayScreenObjects()
{
	this->initialiseCommunityCardSprites();
	this->initialisePlayerCardsSprites();
	this->initialiseGeneralPlayButtons();
	this->initialiseInstructions();
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
	this->player1card1.setPosition((this->videomode.width / 2) - 40.f, 900.f);

	this->player1card2.setTexture(this->deck.backOfCardTexture);
	this->player1card2.setScale(1.5f, 1.5f);
	this->player1card2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player1card2.setPosition((this->videomode.width / 2) + 40.f, 900.f);

	this->player2card1.setTexture(this->deck.backOfCardTexture);
	this->player2card1.setRotation(90.f);
	this->player2card1.setScale(1.5f, 1.5f);
	this->player2card1.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player2card1.setPosition(this->videomode.width / 30, 700.f);

	this->player2card2.setTexture(this->deck.backOfCardTexture);
	this->player2card2.setScale(1.5f, 1.5f);
	this->player2card2.setRotation(90.f);
	this->player2card2.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	this->player2card2.setPosition(this->videomode.width / 30, 620.f);


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
	this->pokerHandsText.setFillColor(sf::Color::Black);
	this->pokerHandsText.setFont(font);
	this->pokerHandsText.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->pokerHandsText.getLocalBounds();
	this->pokerHandsText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->pokerHandsText.setPosition(this->pokerHandsButton.getPosition());

	if (this->isPractice) {
		this->setRectangleProperties(this->oddsViewButton, sf::Vector2f(this->videomode.width / 12, this->videomode.height / 20), sf::Vector2f(1750.f, 320.f), sf::Color::Red);
		this->setTextProperties(this->oddsViewText, "Odds View", sf::Vector2f(this->oddsViewButton.getPosition()), int(this->videomode.width / 80), sf::Color::Black);
	}
	

}
void PokerOfflineUi::initialiseReadyUpButton()
{
	this->readyUpButton.setFillColor(sf::Color::Red);
	this->readyUpButton.setSize(sf::Vector2f(this->videomode.width/15, this->videomode.height/25));
	sf::FloatRect pokerHandsRectangle = this->readyUpButton.getLocalBounds();
	this->readyUpButton.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->readyUpButton.setPosition(this->videomode.width/2+200.f, 800.f);


	this->readyUpText.setString("Ready Up!");
	this->readyUpText.setFillColor(sf::Color::Black);
	this->readyUpText.setFont(font);
	this->readyUpText.setCharacterSize(int(this->videomode.width / 100));
	pokerHandsRectangle = this->readyUpText.getLocalBounds();
	this->readyUpText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->readyUpText.setPosition(this->readyUpButton.getPosition());
}

void PokerOfflineUi::initialiseBettingObjects()
{
	//Confrim raise button
	this->raiseButton.setFillColor(sf::Color::Red);
	this->raiseButton.setSize(sf::Vector2f(this->videomode.width/20, this->videomode.height/25));
	sf::FloatRect pokerHandsRectangle = this->raiseButton.getLocalBounds();
	this->raiseButton.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseButton.setPosition(this->videomode.width/2-130, 880.f);


	this->raiseText.setString("Confirm!");
	this->raiseText.setFillColor(sf::Color::Black);
	this->raiseText.setFont(font);
	this->raiseText.setCharacterSize(int(this->videomode.width / 100));
	pokerHandsRectangle = this->raiseText.getLocalBounds();
	this->raiseText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseText.setPosition(this->raiseButton.getPosition());

	//Raise Increment button
	this->raiseIncrementButton.setFillColor(sf::Color::Red);
	this->raiseIncrementButton.setSize(sf::Vector2f(this->videomode.height/25, this->videomode.height/25));
	pokerHandsRectangle = this->raiseIncrementButton.getLocalBounds();
	this->raiseIncrementButton.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseIncrementButton.setPosition(this->videomode.width/2-100, 800.f);


	this->raiseIncrementText.setString("+");
	this->raiseIncrementText.setFillColor(sf::Color::Black);
	this->raiseIncrementText.setFont(font);
	this->raiseIncrementText.setCharacterSize(int(this->videomode.width / 60));
	pokerHandsRectangle = this->raiseIncrementText.getLocalBounds();
	this->raiseIncrementText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseIncrementText.setPosition(this->raiseIncrementButton.getPosition());

	//Raise Decrement Button
	

	this->raiseDecrementButton.setFillColor(sf::Color::Red);
	this->raiseDecrementButton.setSize(sf::Vector2f(this->videomode.height/25, this->videomode.height/25));
	pokerHandsRectangle = this->raiseDecrementButton.getLocalBounds();
	this->raiseDecrementButton.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseDecrementButton.setPosition(this->videomode.width/2+100, 800.f);

	this->raiseDecrementText.setString("-");
	this->raiseDecrementText.setFillColor(sf::Color::Black);
	this->raiseDecrementText.setFont(font);
	this->raiseDecrementText.setCharacterSize(int(this->videomode.width / 40));
	pokerHandsRectangle = this->raiseDecrementText.getLocalBounds();
	this->raiseDecrementText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseDecrementText.setPosition(this->raiseDecrementButton.getPosition());

	//Raise Text Box
	this->raiseBox.setFillColor(sf::Color::White);
	this->raiseBox.setSize(sf::Vector2f(this->videomode.width/15, this->videomode.height/25));
	pokerHandsRectangle = this->raiseBox.getLocalBounds();
	this->raiseBox.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseBox.setPosition(this->videomode.width/2, 800.f);

	this->raiseAmount.setString("0");
	this->raiseAmount.setFillColor(sf::Color::Black);
	this->raiseAmount.setFont(font);
	this->raiseAmount.setCharacterSize(int(this->videomode.width / 100));
	pokerHandsRectangle = this->raiseAmount.getLocalBounds();
	this->raiseAmount.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->raiseAmount.setPosition(this->raiseBox.getPosition());
}

void PokerOfflineUi::initialisePlayerStatuses(){
	this->playerName.setString("Joe");
	this->playerName.setFillColor(sf::Color::Black);
	this->playerName.setFont(font);
	this->playerName.setCharacterSize(int(this->videomode.width / 80));
	sf::FloatRect pokerHandsRectangle = this->playerName.getLocalBounds();
	this->playerName.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->playerName.setPosition(this->videomode.width/2, 970);
	
	

	this->AIName.setString("AI1");
	this->AIName.setFillColor(sf::Color::Black);
	this->AIName.setFont(font);
	this->AIName.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AIName.getLocalBounds();
	this->AIName.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AIName.setPosition(this->videomode.width / 30, 470.f);
	

	this->AI2Name.setString("AI2");
	this->AI2Name.setFillColor(sf::Color::Black);
	this->AI2Name.setFont(font);
	this->AI2Name.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AI2Name.getLocalBounds();
	this->AI2Name.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AI2Name.setPosition(this->videomode.width / 30, 760.f);
	

	this->AI3Name.setString("AI3");
	this->AI3Name.setFillColor(sf::Color::Black);
	this->AI3Name.setFont(font);
	this->AI3Name.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AI3Name.getLocalBounds();
	this->AI3Name.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AI3Name.setPosition(this->videomode.width - this->videomode.width / 30, 670.f);
	
	
	this->playerStatus.setString("Waiting");
	this->playerStatus.setFillColor(sf::Color::Black);
	this->playerStatus.setFont(font);
	this->playerStatus.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->playerStatus.getLocalBounds();
	this->playerStatus.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->playerStatus.setPosition(this->videomode.width/2, 1000);
	
	

	this->AIStatus.setString("Waiting");
	this->AIStatus.setFillColor(sf::Color::Black);
	this->AIStatus.setFont(font);
	this->AIStatus.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AIStatus.getLocalBounds();
	this->AIStatus.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AIStatus.setPosition(this->videomode.width / 30, 500.f);
	

	this->AI2Status.setString("Waiting");
	this->AI2Status.setFillColor(sf::Color::Black);
	this->AI2Status.setFont(font);
	this->AI2Status.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AI2Status.getLocalBounds();
	this->AI2Status.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AI2Status.setPosition(this->videomode.width / 30, 790.f);
	

	this->AI3Status.setString("Waiting");
	this->AI3Status.setFillColor(sf::Color::Black);
	this->AI3Status.setFont(font);
	this->AI3Status.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AI3Status.getLocalBounds();
	this->AI3Status.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AI3Status.setPosition(this->videomode.width - this->videomode.width / 30, 700.f);
	

}

void PokerOfflineUi::initialiseFoldButton()
{
	this->foldButton.setFillColor(sf::Color::Red);
	this->foldButton.setSize(sf::Vector2f(this->videomode.width/20, this->videomode.height/25));
	sf::FloatRect pokerHandsRectangle = this->foldButton.getLocalBounds();
	this->foldButton.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->foldButton.setPosition(this->videomode.width/2-130.f, 930.f);


	this->foldText.setString("Fold");
	this->foldText.setFillColor(sf::Color::Black);
	this->foldText.setFont(font);
	this->foldText.setCharacterSize(int(this->videomode.width / 100));
	pokerHandsRectangle = this->foldText.getLocalBounds();
	this->foldText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->foldText.setPosition(this->foldButton.getPosition());
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
	// this->gameStateText.setFillColor(sf::Color::Black);
	// sf::FloatRect rect = this->gameStateText.getLocalBounds();
	// this->gameStateText.setOrigin(rect.left + round(rect.width / 2.0f), rect.top + round(rect.height / 2.0f));
	// this->gameStateText.setPosition(this->gameStateRect.getPosition());
	this->gameStateText.setString("Hand being dealt");
	this->potText.setFillColor(sf::Color::Black);
	this->hasStarted = true;
	
	this->pokerGame->startGame();
	
}

void PokerOfflineUi::setPlayer(Player* player){

	this->player = player;
	
}
Decision PokerOfflineUi::waitForPlayerDecision(int currentBet){
	this->setWaitingStatuses();
	this->playerBetAmount = 0;
	while(!this->readyUp){
		this->update();
		this->render();
	}
	
	std::cout<<"Player bet amount = "<<this->playerBetAmount<<std::endl;
	this->player->chipsToBet = (this->playerBetAmount);

	return this->decision;
}

void PokerOfflineUi::winGame()
{
	this->~PokerOfflineUi();

	HandWonUI* display = new HandWonUI();

	while (display->isGameRunning) {
		display->update();
		display->render();

	}

}
void PokerOfflineUi::loseGame()
{
	this->window->close();
	HandLostUI* display = new HandLostUI();

	while (display->isGameRunning) {
		display->update();
		display->render();

	}
}
void PokerOfflineUi::updateOnBet()
{

}
void PokerOfflineUi::updateCommunityCardsOnFlop(Card& c1,Card& c2,Card& c3)
{
	this->communityCard1.setTexture(this->deck.currentDeck[c1.index].cardFace);
	this->render();
	
	AudioManager::getInstance().playSound("dealCard1");
	delay(500);
	this->communityCard2.setTexture(this->deck.currentDeck[c2.index].cardFace);
	this->render();
	
	AudioManager::getInstance().playSound("dealCard2");
	delay(500);
	this->communityCard3.setTexture(this->deck.currentDeck[c3.index].cardFace);
	this->render();
	
	AudioManager::getInstance().playSound("dealCard1");
}
void PokerOfflineUi::updateCommunityCardsOnTurn(Card& card)
{
	this->communityCard4.setTexture(this->deck.currentDeck[card.index].cardFace);
	this->render();
	
	AudioManager::getInstance().playSound("dealCard1");
}
void PokerOfflineUi::updateCommunityCardsOnRiver(Card& card)
{
	this->communityCard5.setTexture(this->deck.currentDeck[card.index].cardFace);
	this->render();

	AudioManager::getInstance().playSound("dealCard1");
}
void PokerOfflineUi::updatePlayerCards(std::vector<Card> cards)
{
	
	this->player1card1.setTexture(this->deck.currentDeck[cards[0].index].cardFace);
	this->render();
	
	AudioManager::getInstance().playSound("dealCard1");
	
	delay(500);
	this->player1card2.setTexture(this->deck.currentDeck[cards[1].index].cardFace);
	this->render();
	
	AudioManager::getInstance().playSound("dealCard2");

}

void PokerOfflineUi::updateShowdown(std::vector<Card> aiCards, std::vector<Card> ai2Cards, std::vector<Card> ai3Cards, int winner) 
{
	this->showdownUpdateCards(aiCards, ai2Cards,ai3Cards);
	this->render();
	
	sf::sleep(sf::milliseconds(5000));
	this->window->close();
	
	if (winner == 0) {
		winGame();
	}
	else {
		loseGame();
	}
	
	


}
void PokerOfflineUi::initialisePot(){
	this->potText.setString("Pot:\n "+std::to_string(this->potAmount));
	this->potText.setFillColor(sf::Color::Transparent);
	this->potText.setFont(font);
	this->potText.setCharacterSize(int(this->videomode.width / 80));
	sf::FloatRect pokerHandsRectangle = this->potText.getLocalBounds();
	this->potText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->potText.setPosition(this->videomode.width/2, 500);
}

void PokerOfflineUi::initialisePlayerChips()
{
	this->playerChips.setString("Your Chips:\n "+std::to_string(this->playerChipsInt));
	this->playerChips.setFillColor(sf::Color::Black);
	this->playerChips.setFont(font);
	this->playerChips.setCharacterSize(int(this->videomode.width / 80));
	sf::FloatRect pokerHandsRectangle = this->playerChips.getLocalBounds();
	this->playerChips.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->playerChips.setPosition(this->videomode.width/2 + 180, 900);
	

	this->AIChips.setString("Chips:\n "+std::to_string(this->AIChipsInt));
	this->AIChips.setFillColor(sf::Color::Black);
	this->AIChips.setFont(font);
	this->AIChips.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AIChips.getLocalBounds();
	this->AIChips.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AIChips.setPosition(this->videomode.width / 12, 660.f);
	

	this->AI2Chips.setString("Chips:\n "+std::to_string(this->AI2ChipsInt));
	this->AI2Chips.setFillColor(sf::Color::Black);
	this->AI2Chips.setFont(font);
	this->AI2Chips.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AI2Chips.getLocalBounds();
	this->AI2Chips.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AI2Chips.setPosition(this->videomode.width / 12, 360.f);
	

	this->AI3Chips.setString("Chips:\n "+std::to_string(this->AI3ChipsInt));
	this->AI3Chips.setFillColor(sf::Color::Black);
	this->AI3Chips.setFont(font);
	this->AI3Chips.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->AI3Chips.getLocalBounds();
	this->AI3Chips.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->AI3Chips.setPosition(this->videomode.width - this->videomode.width / 12, 560.f);
	

	// this->AI4Chips.setString("Player 4 chips:\n "+std::to_string(this->AI4ChipsInt));
	// this->AI4Chips.setFillColor(sf::Color::Black);
	// this->AI4Chips.setFont(font);
	// this->AI4Chips.setCharacterSize(int(this->videomode.width / 80));
	// pokerHandsRectangle = this->AI4Chips.getLocalBounds();
	// this->AI4Chips.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	// this->AI4Chips.setPosition(this->gameStateRect.getPosition());



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
	this->gameStateText.setFillColor(sf::Color::Black);
	this->gameStateText.setFont(font);
	this->gameStateText.setCharacterSize(int(this->videomode.width / 80));
	pokerHandsRectangle = this->gameStateText.getLocalBounds();
	this->gameStateText.setOrigin(pokerHandsRectangle.left + round(pokerHandsRectangle.width / 2.0f), pokerHandsRectangle.top + round(pokerHandsRectangle.height / 2.0f));
	this->gameStateText.setPosition(this->gameStateRect.getPosition());
}
void PokerOfflineUi::showPokerHands(){
	
}

void PokerOfflineUi::updatePlayerChipsDisplay(){
	this->playerChips.setString("Your Chips:\n "+std::to_string(this->playerChipsInt));
	this->AIChips.setString("Chips:\n "+std::to_string(this->AIChipsInt));
	this->AI2Chips.setString("Chips:\n "+std::to_string(this->AI2ChipsInt));
	this->AI3Chips.setString("Chips:\n "+std::to_string(this->AI3ChipsInt));
}

void PokerOfflineUi::renderText(sf::RenderTarget& target)
{
	target.draw(this->title);
	target.draw(this->oddsViewInstructions);
	target.draw(this->instructions);
	target.draw(this->pokerHandsText);
	target.draw(this->gameStateText);
	target.draw(this->readyUpText);
	target.draw(this->foldText);
	target.draw(this->raiseText);
	target.draw(this->raiseAmount);
	target.draw(this->raiseIncrementText);
	target.draw(this->raiseDecrementText);
	target.draw(this->playerChips);
	target.draw(this->potText);


	target.draw(playerStatus);
	target.draw(AIStatus);
	target.draw(AI2Status);
	target.draw(AI3Status);

	target.draw(playerName);
	target.draw(AIName);
	target.draw(AI2Name);
	target.draw(AI3Name);
	
	target.draw(AIChips);
	target.draw(AI2Chips);
	target.draw(AI3Chips);

	if (this->isPractice) {
		
		target.draw(this->oddsViewButton);
		target.draw(this->oddsViewText);
	}

	/*if (this->isLookingAtHands){
		target.draw(this->pokerHandsSprite);
		target.draw(this->closePokerHandsButton);
		target.draw(this->closePokerHandsText);
	}*/
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
	target.draw(this->readyUpButton);
	target.draw(this->foldButton);
	target.draw(this->raiseBox);
	target.draw(this->raiseButton);
	target.draw(this->raiseIncrementButton);
	target.draw(this->raiseDecrementButton);

}
void PokerOfflineUi::resetReadyAndDecision()
{
	this->readyUp = false;
	this->decision = Decision::NotMade;
}
void PokerOfflineUi::updatePlayerUIs()
{
	this->raiseAmount.setString(std::to_string(this->chipsRaisedInt));
	this->playerChips.setString("Your Chips:\n "+std::to_string(this->playerChipsInt));
	this->potText.setString("Pot:\n "+std::to_string(this->potAmount));
	this->AIChips.setString("Chips:\n "+std::to_string(this->AIChipsInt));
	this->AI2Chips.setString("Chips:\n "+std::to_string(this->AI2ChipsInt));
	this->AI3Chips.setString("Chips:\n "+std::to_string(this->AI3ChipsInt));
	
}


void PokerOfflineUi::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	this->updatePlayerUIs();

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
			else if (this->instructions.getGlobalBounds().contains(this->mousePositionFloat)) {
				AudioManager::getInstance().playMenuNoise();
				this->inInstruction = true;

				while (this->inInstruction) {
					this->updateInstruction();
					this->renderInstruction();
				}
			}
			
			else if (this->oddsViewInstructions.getGlobalBounds().contains(this->mousePositionFloat)&&this->isPractice) {
				AudioManager::getInstance().playMenuNoise();
				this->inOddsViewHelp = true;

				while (this->inOddsViewHelp) {
					this->updateOddsViewHelp();
					this->renderOddsViewHelp();
				}
			}
		}
		
		
	}
	else
	{
		this->lMBDown = false;
	}
}
void PokerOfflineUi::processPlayerChoices()
{
	
	//check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	{
		if (!this->lMBDown) 
		{
			this->lMBDown = true;
			
			if (this->readyUpButton.getGlobalBounds().contains(this->mousePositionFloat))
			{
				this->processReadyUp();
				return;
			}
			else if (this->pokerHandsButton.getGlobalBounds().contains(this->mousePositionFloat)) {
				this->processPokerHandsButton();
			}
			else if (this->oddsViewButton.getGlobalBounds().contains(this->mousePositionFloat)) {
				
				this->processOddsViewButton();
			}
			else if (this->raiseIncrementButton.getGlobalBounds().contains(this->mousePositionFloat)){
				if(this->chipsRaisedInt==this->playerChipsInt){
				this->chipsRaisedInt = 0;
				}
				else{
					this->chipsRaisedInt++;
				}
			}
			else if (this->raiseDecrementButton.getGlobalBounds().contains(this->mousePositionFloat)){
				if(this->chipsRaisedInt==0){
					this->chipsRaisedInt = this->playerChipsInt;
				}
				else{
					this->chipsRaisedInt--;
				}
				
			}
        
			// Check if the user clicked inside the text box
			else if (this->raiseButton.getGlobalBounds().contains(this->mousePositionFloat))
			{
				std::string money = this->raiseAmount.getString();
				
				this->playerBetAmount = std::stoi(money);

				
				return;
			}
			else if (raiseBox.getGlobalBounds().contains(this->mousePositionFloat))
			{
		
				this->raiseBoxActive = true;
				return;
			}
			else if (this->foldButton.getGlobalBounds().contains(this->mousePositionFloat)) {
				std::cout << "folding" << std::endl;
				this->hasFolded = true;
			}
			
			else if (this->instructions.getGlobalBounds().contains(this->mousePositionFloat)) {
				AudioManager::getInstance().playMenuNoise();
				this->inInstruction = true;

				while (this->inInstruction) {
					this->updateInstruction();
					this->renderInstruction();
				}
			}

			else if (this->oddsViewInstructions.getGlobalBounds().contains(this->mousePositionFloat) && this->isPractice) {
				AudioManager::getInstance().playMenuNoise();
				this->inOddsViewHelp = true;

				while (this->inOddsViewHelp) {
					this->updateOddsViewHelp();
					this->renderOddsViewHelp();
				}
			}
			
            
	
		}
		
		
	}
	else
	{
		this->lMBDown=false;
		return;
	}
}

void PokerOfflineUi::processReadyUp(){
	std::cout<< "player bet amount in process ready up is "<<this->playerBetAmount<<std::endl;
	if (this->playerBetAmount>0){

		this->playerChipsInt = this->playerChipsInt - this->playerBetAmount;
		this->potAmount = this->potAmount + this->playerBetAmount;
		this->chipsRaisedInt = 0;
		this->decision = Decision::Raise;
	}
	else if(this->hasFolded){
		this->decision = Decision::Fold;
	}
	else if(this->playerBetAmount==0){
		
		if (this->groupHighBet-this->playerHighBet!=0){

			this->decision = Decision::Call;
		}
		else{
			std::cout<<" in correct place."<<std::endl;
			this->decision = Decision::Check;
		}	
		
	}
	else{
		std::cout<<"Something ain't right"<< std::endl;
	}	
	this->readyUp = true;
}

void PokerOfflineUi::updatePlayerStatus(int playerIndex, std::string string) 
{
	if (playerIndex == 0) {
		this->playerStatus.setString(string);
	}
	else if (playerIndex == 1) {
		this->AIStatus.setString(string);
	}
	else if (playerIndex == 2) {
		this->AI2Status.setString(string);
	}
	else if (playerIndex == 3) {
		this->AI3Status.setString(string);
	}
	this->render();
}
void PokerOfflineUi::runPokerHandsWindow()
{
	PokerHandsUI* ui = new PokerHandsUI();
	while (ui->isGameRunning) {
		ui->update();
		ui->render();
	}
}
void PokerOfflineUi::runOddsViewWindow()
{
	

	this->oddsView_->init();
	while (this->oddsView_->isGameRunning) {
		oddsView_->update();
		oddsView_->render();
	}
}
void PokerOfflineUi::updatePlayerChips(int playerIndex, int currentBet)
{
	std::cout << currentBet << std::endl;
	std::string string = std::to_string(currentBet);
	if (playerIndex == 0) {
		this->playerChips.setString(string);
	}
	else if (playerIndex == 1) {
		std::cout << "here" << std::endl;
		this->AIChipsInt -= currentBet;
		this->AIChips.setString(string);
		this->potAmount += currentBet;
		
	}
	else if (playerIndex == 2) {
		this->AI2ChipsInt -= currentBet;
		this->AI2Chips.setString(string);
		this->potAmount += currentBet;
	}
	else if (playerIndex == 3) {
		this->AI3ChipsInt -= currentBet;
		
		this->AI3Chips.setString(string);
		this->potAmount += currentBet;
	}
	
}
void PokerOfflineUi::foldPlayer(int playerIndex)
{
	updatePlayerStatus(playerIndex, "Fold!");
	this->render();

}
void PokerOfflineUi::callPlayer(int playerIndex, int chipAmount){
	std::cout<<"in pokerOfflineUi "<<chipAmount<<std::endl;
	updatePlayerStatus(playerIndex, "Call!");
	updatePlayerChips(playerIndex, chipAmount);

	this->render();
	//this->statuses[playerIndex].setString("Player has called for\n " + std::to_string(chipAmount) + " chips");
	// this->potAmount+= currentBet;
	
}
void PokerOfflineUi::checkPlayer(int playerIndex)
{
	std::cout << "check" << std::endl;
	updatePlayerStatus(playerIndex, "Check!");
	this->render();


}

void PokerOfflineUi::launchUI()
{
	this->launchPoker();
	this->initialiseVariables();
	this->initialiseWindow();
	this->initialiseMenuBar();
	this->initialisePot();
	this->initialisePlayerChips();
	this->initialiseGameStateButton();
	this->initialiseReadyUpButton();
	this->initialisePlayScreenObjects();
	this->initialiseBettingObjects();
	this->initialiseFoldButton();
	this->initialisePlayerStatuses();
}


void PokerOfflineUi::allInPlayer(int playerIndex){

	updatePlayerStatus(playerIndex, "ALL INN!");
	//this->statuses[playerIndex].setString("Player is All in!!!");
	//this->potAmount+=this->playerCashInt[playerIndex];
	//this->playerCashInt[playerIndex] = 0;
	
}
void PokerOfflineUi::raisePlayer(int playerIndex, int currentBet){
	std::string string = "Raise " + std::to_string(currentBet);
	updatePlayerChips(playerIndex, currentBet);
	updatePlayerStatus(playerIndex,string);
	//this->statuses[playerIndex].setString("Player has raised to \n" + std::to_string(currentBet) + " chips");
	this->groupHighBet = currentBet;
	
}
	

void PokerOfflineUi::processStateSwitch(){

	if (this->pokerGame->currentState==Poker::GameState::GameStart){
		
	}
	else if (this->pokerGame->currentState==Poker::GameState::Preflop){
		this->pokerGame->flopState();
		
	}
	else if (this->pokerGame->currentState==Poker::GameState::Flop){
		this->pokerGame->turnState();
	}
	else if (this->pokerGame->currentState==Poker::GameState::Turn){
		this->pokerGame->riverState();
	}
	else if (this->pokerGame->currentState==Poker::GameState::River){
	
	}
	else if (this->pokerGame->currentState==Poker::GameState::ShowDown){

	}
	else if (this->pokerGame->currentState==Poker::GameState::GameOver){

	}
}

void PokerOfflineUi::processPokerHandsButton()
{
	this->isPokerHandsOpen = true;
	this->pokerHandsThread = std::thread(&PokerOfflineUi::runPokerHandsWindow, this);
	

}

void PokerOfflineUi::processOddsViewButton()
{
	this->isOddsViewOpen = true;
	this->oddsViewThread = std::thread(&PokerOfflineUi::runOddsViewWindow, this);
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

void PokerOfflineUi::setVariables(int money, bool isPractice) {
	this->chipsPerPlayer = money;
	this->isPractice = isPractice;
}

void PokerOfflineUi::updatePot(int pot)
{

}


void PokerOfflineUi::startBetting(){
	this->pokerGame->bettingState();
}
void PokerOfflineUi::showdownUpdateCards(std::vector<Card> aiCards, std::vector<Card> ai2Cards, std::vector<Card> ai3Cards)
{
	player2card1.setTexture(deck.currentDeck[aiCards[0].index].cardFace);
	player2card2.setTexture(deck.currentDeck[aiCards[1].index].cardFace);

	player3card1.setTexture(deck.currentDeck[ai2Cards[0].index].cardFace);
	player3card2.setTexture(deck.currentDeck[ai2Cards[1].index].cardFace);

	player4card1.setTexture(deck.currentDeck[ai3Cards[0].index].cardFace);
	player4card2.setTexture(deck.currentDeck[ai3Cards[1].index].cardFace);
}
//Constructor and Destructor
PokerOfflineUi::PokerOfflineUi()
{
	

}

PokerOfflineUi::~PokerOfflineUi()
{
	this->pokerHandsThread.join();
	//this->oddsViewThread.join();
	//this->launchOddsViewThread.join();
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

	this->processPlayerChoices();
	


	
}
