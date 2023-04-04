#include "PokerOffline.h"

void PokerOffline::initialiseVariables()
{
	this->window = nullptr;
	this->potAmount = 0;
	this->lMBDown = false;

	this->deck.initialiseDeck();	
	

}

void PokerOffline::initialiseWindow() 
{
	this->videomode.height = 1080;
	this->videomode.width = 1920;
	/*this->videomode.getDesktopMode;*/
	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}
void PokerOffline::initialiseMenuBar()
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

void PokerOffline::initialisePlayScreenObjects()
{
	this->initialiseCommunityCardSprites();
	this->initialisePlayerCardsSprites();
	this->initialiseGeneralPlayButtons();
}

void PokerOffline::initialiseCommunityCardSprites()
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

void PokerOffline::initialisePlayerCardsSprites()
{

}

void PokerOffline::initialiseGeneralPlayButtons()
{
}

void PokerOffline::initialisePlayerButtons()
{
}



void PokerOffline::renderText(sf::RenderTarget& target)
{
	target.draw(this->title);
	target.draw(this->settings);
	target.draw(this->instructions);
}

void PokerOffline::renderGameObjects(sf::RenderTarget& target)
{
	target.draw(this->communityCard1);
	target.draw(this->communityCard2);
	target.draw(this->communityCard3);
	target.draw(this->communityCard4);
	target.draw(this->communityCard5);
}


void PokerOffline::render()
{
	this->window->clear(sf::Color(0, 100, 0));

	this->window->draw(this->menuBar);

	this->renderText(*this->window);

	this->renderGameObjects(*this->window);


	this->window->display();

}


const bool PokerOffline::isGameRunning() const
{
	return this->window->isOpen();
}


void PokerOffline::pollEvents() 
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
PokerOffline::PokerOffline()
{
	this->initialiseVariables();
	this->initialiseWindow();
	this->initialiseMenuBar();
	this->initialisePlayScreenObjects();


}

PokerOffline::~PokerOffline()
{
	delete this->window;
}


void PokerOffline::updateMousePositions()
{
	this->mousePositionInt = sf::Mouse::getPosition(*this->window);
	this->mousePositionFloat = this->window->mapPixelToCoords(this->mousePositionInt);
}
void PokerOffline::update() {

	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

	
}

