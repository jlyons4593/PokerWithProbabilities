#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>
#include "AudioManager.cpp"

#include "PokerOfflineUi.h"
#include "PokerOfflineUiSingleton.h"




//Private Functions
void Game::initialiseVariables()
{
	this->window = nullptr;
	
	this->lMBDown = false;
	this->inDisclaimer = false;
	this->inInstruction = false;
	this->inSettings = false;
	this->playerMoney = 150;
	this->volume = 10;
	this->masterPlayerMoney = 150;

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
	this->setTextProperties(this->playVsAi, "Play vs Computer", sf::Vector2f((this->videomode.width / 2), 200 + (this->videomode.height / 8)), int(videomode.width / 30), sf::Color::White);

	// Practice
	this->setTextProperties(this->practice, "Practice", sf::Vector2f((this->videomode.width / 2), 200 + 2 * (this->videomode.height / 8)), int(videomode.width / 30), sf::Color::White);
	
	//settings item
	this->setTextProperties(this->settings, "Settings", sf::Vector2f((this->videomode.width / 2), 200 + 3 * (this->videomode.height / 8)), int(videomode.width / 30), sf::Color::White);

	// how to play choice
	this->setTextProperties(this->disclaimer, "Disclaimer", sf::Vector2f((this->videomode.width / 2), 200 + 4 * (this->videomode.height / 8)), int(videomode.width / 30), sf::Color::White);
	
	//instructions choice
	this->setTextProperties(this->instructions, "Instructions", sf::Vector2f((this->videomode.width / 2), 200 + 5 * (this->videomode.height / 8)), int(videomode.width / 30), sf::Color::White);


	

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

void Game::initialiseDisclaimerUI()
{
	std::string title = "Poker & Probabilities - Gambling Awareness Disclaimer:";
	std::string text = "Poker & Probabilities is an educationaland entertaining game that explores the concepts of poker \nand probability. It does not involve real money wagers, and all chips or virtual currencies used hold\nno cash value.The game emphasizes understanding probability rather than promoting gambling \nbehavior.Please note that the outcomes are determined by random algorithms and simulated\nscenarios, which do not guarantee similar results in actual gambling activities.It is important to \napproach Poker& Probabilities responsibly, recognizing its recreational natureand seeking support\n from appropriate resources if needed.The creators and operators of Poker & Probabilities do not \nendorse real money gambling or any form of illegal gambling activities and shall not be held liable for \nany personal, financial, or legal consequences resulting from participating in the game or related\nactivities.";
	
	this->setTextProperties(this->disclaimerText, text, sf::Vector2f(50, this->videomode.height / 2 - 100), int(videomode.width / 50), sf::Color::White);
	this->setTextProperties(this->disclaimerTitle, title, sf::Vector2f(this->videomode.width / 2, this->videomode.height / 2 - 150), int(videomode.width / 50), sf::Color::White);
	this->disclaimerText.setOrigin(0,0);
	this->setTextProperties(this->backText, "Back", sf::Vector2f(50, 50), int(videomode.width / 50), sf::Color::White);
	this->setRectangleProperties(this->backButton, sf::Vector2f(70.f, 80.f), sf::Vector2f(50, 50), sf::Color::Black);

}

void Game::updateDisclaimer()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	this->handleDisclaimerUpdate();
}

void Game::renderDisclaimer()
{
	this->window->clear(sf::Color(0, 100, 0));



	//draw menu
	this->window->draw(this->menuBar);
	this->window->draw(this->title);
	this->window->draw(this->disclaimerText);
	this->window->draw(this->backButton);
	this->window->draw(this->backText);
	this->window->draw(this->disclaimerTitle);
	



	this->window->display();
}

void Game::handleDisclaimerUpdate()
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
				this->inDisclaimer = false;
				this->inInstruction = false;
				this->inSettings = false;
			}
		}

	}
	else
	{
		this->lMBDown = false;
	}
}

void Game::initialiseInstructionUI()
{
	std::string title = "Instructions";
	this->setTextProperties(this->instructionTitle, title, sf::Vector2f(this->videomode.width / 2, this->videomode.height / 2 - 150), int(videomode.width / 40), sf::Color::White);
	std::string text = "Choose between our 2 game modes.\nPractice gives you access to the Odds view while playing poker hands against AI. \nIn Play vs AI you're alone.\nPlay hands against the computer and improve your skills and collect achievements.\nIf you don't know the basics of poker you can learn as you go or head to www.learnpoker.com \nThis game aims to help improve your poker skills.\nThe odds view given in the practice mode allows players\nto access some helpful statistics that can aid you in getting better at Poker!";
	this->setTextProperties(this->instructionText, text, sf::Vector2f(50, this->videomode.height / 2-100), int(videomode.width / 50), sf::Color::White);
	this->instructionText.setOrigin(0, 0);
}

void Game::updateInstruction()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	this->handleDisclaimerUpdate();
}

void Game::renderInstruction()
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



void Game::initialiseSettingsUI()
{
	//Title
	this->setTextProperties(this->settingsText, "Settings", sf::Vector2f(this->videomode.width / 2, 200), int(videomode.width / 30), sf::Color::White);
	// Settings
	this->setTextProperties(this->volumeText, "Volume", sf::Vector2f(this->videomode.width / 2 -200, this->videomode.height / 2), int(videomode.width / 50), sf::Color::White);
	this->setTextProperties(this->playerMoneyText, "Money per Player", sf::Vector2f(this->videomode.width / 2+200, this->videomode.height / 2), int(videomode.width / 50), sf::Color::White);
	
	// Volume adjusters

	this->setTextProperties(this->volumeIncrementText, "+", sf::Vector2f(this->videomode.width / 2-135, this->videomode.height / 2 + 50), int(videomode.width / 40), sf::Color::White);
	this->setRectangleProperties(this->volumeIncrementButton, sf::Vector2f(40.f, 40.f), this->volumeIncrementText.getPosition(), sf::Color::Black);
	
	this->setTextProperties(this->volumeDecrementText, "-", sf::Vector2f(this->videomode.width / 2-265, this->videomode.height / 2 + 50), int(videomode.width / 25), sf::Color::White);
	this->setRectangleProperties(this->volumeDecrementButton, sf::Vector2f(40.f, 40.f), this->volumeDecrementText.getPosition(), sf::Color::Black);

	this->setTextProperties(this->volumeDisplayText, std::to_string(volume), sf::Vector2f(this->videomode.width / 2 - 200, this->videomode.height / 2 + 50), int(videomode.width / 50), sf::Color::Black);
	this->setRectangleProperties(this->volumeDisplayRect, sf::Vector2f(70.f, 40.f), this->volumeDisplayText.getPosition(), sf::Color::White);

	
	// Player Money adjusters
	this->setTextProperties(this->playerMoneyDecrementText, "-", sf::Vector2f(this->videomode.width / 2+135, this->videomode.height / 2 + 50), int(videomode.width / 25), sf::Color::White);
	this->setRectangleProperties(this->playerMoneyDecrementButton, sf::Vector2f(40.f, 40.f), this->playerMoneyDecrementText.getPosition(), sf::Color::Black);

	this->setTextProperties(this->playerMoneyIncrementText, "+", sf::Vector2f(this->videomode.width / 2+265, this->videomode.height / 2 + 50), int(videomode.width / 40), sf::Color::White);
	this->setRectangleProperties(this->playerMoneyIncrementButton, sf::Vector2f(40.f, 40.f), this->playerMoneyIncrementText.getPosition(), sf::Color::Black);

	this->setTextProperties(this->playerMoneyDisplayText, "150", sf::Vector2f(this->videomode.width / 2+200, this->videomode.height / 2 + 50), int(videomode.width / 50), sf::Color::Black);
	this->setRectangleProperties(this->playerMoneyDisplayRect, sf::Vector2f(70.f, 40.f), this->playerMoneyDisplayText.getPosition(), sf::Color::White);
	
	
	this->setTextProperties(this->applyChangesText, "Apply", sf::Vector2f(this->videomode.width / 2, this->videomode.height / 2 + 250), int(videomode.width / 50), sf::Color::White);
	this->setRectangleProperties(this->applyChangesButton, sf::Vector2f(100.f, 60.f), this->applyChangesText.getPosition(), sf::Color::Black);


	
}

void Game::updateSettings()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();
	this->handleSettingsUpdate();
}

void Game::renderSettings()
{
	this->window->clear(sf::Color(0, 100, 0));



	//draw menu
	this->window->draw(this->menuBar);
	this->window->draw(this->title);
	this->window->draw(this->settingsText);
	this->window->draw(this->playerMoneyText);
	this->window->draw(this->volumeText);


	this->window->draw(this->volumeDecrementButton);
	this->window->draw(this->volumeIncrementButton);
	this->window->draw(this->volumeIncrementText);
	this->window->draw(this->volumeDecrementText);

	this->window->draw(this->playerMoneyIncrementButton);
	this->window->draw(this->playerMoneyDecrementButton);
	this->window->draw(this->playerMoneyDecrementText);
	this->window->draw(this->playerMoneyIncrementText);
	

	this->window->draw(this->volumeDisplayRect);
	this->window->draw(this->volumeDisplayText);

	this->window->draw(this->playerMoneyDisplayRect);
	this->window->draw(this->playerMoneyDisplayText);


	this->window->draw(this->backButton);
	this->window->draw(this->backText);

	this->window->draw(this->applyChangesButton);
	this->window->draw(this->applyChangesText);



	this->window->display();
}

void Game::handleSettingsUpdate()
{
	//check if clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!this->lMBDown) {
			this->lMBDown = true;
			if (this->backButton.getGlobalBounds().contains(this->mousePositionFloat))
			{

				AudioManager::getInstance().playMenuNoise();
				this->lMBDown = true;
				this->inDisclaimer = false;
				this->inInstruction = false;
				this->inSettings = false;


			}
			else if (this->playerMoneyIncrementButton.getGlobalBounds().contains(this->mousePositionFloat)) {

				if (this->playerMoney == 500) { this->playerMoney = 50; }
				else {
					this->playerMoney += 10;
				}
				this->playerMoneyDisplayText.setString(std::to_string(this->playerMoney));

			}
			else if (this->playerMoneyDecrementButton.getGlobalBounds().contains(this->mousePositionFloat)) {

				if (this->playerMoney == 50) { this->playerMoney = 500; }
				else {
					this->playerMoney -= 10;
				}
				this->playerMoneyDisplayText.setString(std::to_string(this->playerMoney));

			}
			else if (this->volumeIncrementButton.getGlobalBounds().contains(this->mousePositionFloat)) {

				if (this->volume != 10) {
					this->volume += 1;
				}
				this->volumeDisplayText.setString(std::to_string(this->volume));

			}
			else if (this->volumeDecrementButton.getGlobalBounds().contains(this->mousePositionFloat)) {

				if (this->volume != 0) {
					this->volume -= 1;
				}
				this->volumeDisplayText.setString(std::to_string(this->volume));

			}
			else if (this->applyChangesButton.getGlobalBounds().contains(this->mousePositionFloat)) {

				
				this->masterPlayerMoney = this->playerMoney;
				AudioManager::getInstance().setVolume(this->volume);

			}


		}
		
	}
	else
	{
		this->lMBDown = false;
	}
}




//Constructor and Destructor
Game::Game()
{
	this->initialiseVariables();
	this->initialiseWindow();
	this->initialiseMenuScreen();
	this->initialiseDisclaimerUI();
	this->initialiseInstructionUI();
	this->initialiseSettingsUI();
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
	target.draw(this->disclaimer);
	target.draw(this->instructions);
	target.draw(this->playVsAi);
	target.draw(this->settings);
	target.draw(this->title);
	target.draw(this->practice);
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
	if (this->disclaimer.getGlobalBounds().contains(this->mousePositionFloat))
	{
		this->inDisclaimer = true;
		AudioManager::getInstance().playMenuNoise();
		while (this->inDisclaimer) {
			this->updateDisclaimer();
			this->renderDisclaimer();
		}
		

	}
	else if (this->settings.getGlobalBounds().contains(this->mousePositionFloat))
	{
		AudioManager::getInstance().playMenuNoise();
		this->inSettings = true;

		while (this->inSettings) {
			this->updateSettings();
			this->renderSettings();
		}
		std::cout << "User chose Settings" << std::endl;
	}
	else if (this->instructions.getGlobalBounds().contains(this->mousePositionFloat))
	{
		AudioManager::getInstance().playMenuNoise();
		this->inInstruction = true;
		
		while (this->inInstruction) {
			this->updateInstruction();
			this->renderInstruction();
		}
		std::cout << "User chose instructions" << std::endl;
	}
	else if (this->practice.getGlobalBounds().contains(this->mousePositionFloat)) 
	{
		AudioManager::getInstance().playMenuNoise();
		PokerOfflineUiSingleton& singleton = PokerOfflineUiSingleton::getInstance();
		PokerOfflineUi* newGame = singleton.getPokerOfflineUi();
		this->window->close();

		newGame->setVariables(masterPlayerMoney, true);
		newGame->launchUI();
		while (!newGame->hasStarted) {
			newGame->initialUpdate();

			newGame->render();
		}
		newGame->startBetting();

		while (newGame->isGameRunning())
		{
			//Update
			newGame->update();

			//Render
			newGame->render();
		}
	}
	else if (this->playVsAi.getGlobalBounds().contains(this->mousePositionFloat))
	{
		AudioManager::getInstance().playMenuNoise();
		PokerOfflineUiSingleton& singleton = PokerOfflineUiSingleton::getInstance();
		PokerOfflineUi* newGame = singleton.getPokerOfflineUi();
		this->window->close();

		newGame->setVariables(masterPlayerMoney, false);
		newGame->launchUI();
		
		while (!newGame->hasStarted){
			newGame->initialUpdate();

			newGame->render();
		}
		newGame->startBetting();

		while (newGame->isGameRunning())
		{
			//Update
			newGame->update();

			//Render
			newGame->render();
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


