#include "PokerHandUI.h"

void PokerHandUI::initVariables()
{
	this->isGameRunning = true;
	this->font.loadFromFile("Fonts/Roboto-Black.ttf");
}

void PokerHandUI::initWindow()
{
	this->videomode.height = 1080;
	this->videomode.width = 1920;

	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

void PokerHandUI::initMenuBar() {

	this->setRectangleProperties(this->menuBar, sf::Vector2f(this->videomode.width, 250.f), sf::Vector2f(this->videomode.width/2, 0), sf::Color::Black);
	this->setTextProperties(this->title, "Poker & Probability", sf::Vector2f(this->videomode.width / 2, 70.f), int(this->videomode.width / 25), sf::Color::White);
	this->setTextProperties(this->settings, "Settings", sf::Vector2f(this->videomode.width / 2 - this->videomode.width / 3, 70.f), int(this->videomode.width / 35), sf::Color::White);
	this->setTextProperties(this->instructions, "Instructions", sf::Vector2f(this->videomode.width / 2 + this->videomode.width / 3, 70.f), int(this->videomode.width / 35), sf::Color::White);
	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->menuBar));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->title));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->settings));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->instructions));
}

void PokerHandUI::initPlayScreenObjects()
{
	this->initCommunityCardSprites();
	this->initPlayerCardsSprites();
	this->initGeneralPlayButtons();
	this->initReadyUpButton();
	this->initBettingObjects();
}

void PokerHandUI::initCommunityCardSprites()
{
	setCardProperties(this->communityCard1, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(static_cast<float>((this->videomode.width / 2) - 2 * (this->videomode.width / 20)), 270.f));

	setCardProperties(this->communityCard2, this->deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) - (this->videomode.width / 20), 270.f));

	setCardProperties(this->communityCard3, this->deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2), 270.f));

	setCardProperties(this->communityCard4, this->deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) + (this->videomode.width / 20), 270.f));

	setCardProperties(this->communityCard5, this->deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) + 2 * (this->videomode.width / 20), 270.f));

	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->communityCard1));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->communityCard2));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->communityCard3));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->communityCard4));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->communityCard5));
}


void PokerHandUI::initPlayerCardsSprites()
{
	setCardProperties(this->player1card1, this->deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) - 40.f, 900.f));
	setCardProperties(this->player1card2, this->deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) + 40.f, 900.f));

	setCardProperties(this->player2card1, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(this->videomode.width / 30, 700.f),90.0f);
	setCardProperties(this->player2card2, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(this->videomode.width / 30, 620.f),90.0f);

	setCardProperties(this->player3card1, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(this->videomode.width / 30, 400.f),90.0f);
	setCardProperties(this->player3card2, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(this->videomode.width / 30, 320.f),90.0f);

	setCardProperties(this->player4card1, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(this->videomode.width - this->videomode.width / 30, 600.f),270.0f);
	setCardProperties(this->player4card2, this->deck.backOfCardTexture, 1.5f, sf::Vector2f(this->videomode.width - this->videomode.width / 30, 520.f),270.0f);

	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player1card1));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player1card2));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player2card1));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player2card2));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player3card1));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player3card2));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player4card1));
	this->drawables.emplace_back(std::make_unique<sf::Sprite>(this->player4card2));
	
}
void PokerHandUI::initGeneralPlayButtons()
{
	this->setRectangleProperties(this->pokerHandsButton, sf::Vector2f(this->videomode.width / 12, this->videomode.height / 20), sf::Vector2f(1750.f, 250.f), sf::Color::Red);
	this->setTextProperties(this->pokerHandsText, "Poker Hands", sf::Vector2f(this->pokerHandsButton.getPosition()), int(this->videomode.width / 80), sf::Color::Black);

	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->pokerHandsButton));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->pokerHandsText));

	this->setRectangleProperties(this->oddsViewButton, sf::Vector2f(this->videomode.width / 12, this->videomode.height / 20), sf::Vector2f(1750.f, 320.f), sf::Color::Red);
	this->setTextProperties(this->oddsViewText, "Odds View", sf::Vector2f(this->oddsViewButton.getPosition()), int(this->videomode.width / 80), sf::Color::Black);

	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->oddsViewButton));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->oddsViewText));


}
void PokerHandUI::initReadyUpButton()
{
	this->setRectangleProperties(this->readyUpButton, sf::Vector2f(this->videomode.width / 15, this->videomode.height / 25), sf::Vector2f(this->videomode.width / 2 + 200.f, 800.f), sf::Color::Red);

	this->setTextProperties(this->readyUpText, "Ready Up!", sf::Vector2f(this->readyUpButton.getPosition()), int(this->videomode.width / 100), sf::Color::Black);

	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->readyUpButton));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->readyUpText));

}
void PokerHandUI::initBettingObjects() 
{
	//Confrim raise button
	this->setRectangleProperties(this->raiseButton, sf::Vector2f(this->videomode.width / 20, this->videomode.height / 25), sf::Vector2f(this->videomode.width / 2 - 130, 880.f), sf::Color::Red);
	this->setTextProperties(this->raiseText, "Confirm", sf::Vector2f(this->raiseButton.getPosition()), int(this->videomode.width / 100), sf::Color::Black);
	
	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->raiseButton));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->raiseText));
	

	//Raise Increment button
	this->setRectangleProperties(this->raiseIncrementButton, sf::Vector2f(this->videomode.height / 25, this->videomode.height / 25), sf::Vector2f(this->videomode.width / 2 - 100, 800.f), sf::Color::Red);
	this->setTextProperties(this->raiseIncrementText, "+", sf::Vector2f(this->raiseIncrementButton.getPosition()), int(this->videomode.width / 60), sf::Color::Black);

	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->raiseIncrementButton));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->raiseIncrementText));
	
	



	//Raise Decrement Button
	
	this->setRectangleProperties(this->raiseDecrementButton, sf::Vector2f(this->videomode.height / 25, this->videomode.height / 25), sf::Vector2f(this->videomode.width / 2 + 100, 800.f), sf::Color::Red);
	this->setTextProperties(this->raiseDecrementText, "-", sf::Vector2f(this->raiseDecrementButton.getPosition()), int(this->videomode.width / 40), sf::Color::Black);

	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->raiseDecrementButton));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->raiseDecrementText));



	//Raise Text Box
	this->setRectangleProperties(this->raiseBox, sf::Vector2f(this->videomode.width / 15, this->videomode.height / 25), sf::Vector2f(this->videomode.width / 2, 800.f), sf::Color::White);
	this->setTextProperties(this->raiseAmount, "0", sf::Vector2f(this->raiseBox.getPosition()), int(this->videomode.width / 100), sf::Color::Black);

	this->drawables.emplace_back(std::make_unique<sf::RectangleShape>(this->raiseBox));
	this->drawables.emplace_back(std::make_unique<sf::Text>(this->raiseAmount));

}
void PokerHandUI::renderObjects(sf::RenderTarget& target)
{
	for (auto& drawable : this->drawables) {
		target.draw(*drawable);
	}
}


void PokerHandUI::update()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

}


void PokerHandUI::render()
{
	// Coloring the window
	this->window->clear(sf::Color(0, 100, 0));
	
	this->renderObjects(*this->window);

	
	// Displaying window
	this->window->display();

}

PokerHandUI::PokerHandUI()
{
	this->initVariables();
	this->initWindow();
	this->initMenuBar();
	this->initPlayScreenObjects();
}

PokerHandUI::~PokerHandUI()
{
}
