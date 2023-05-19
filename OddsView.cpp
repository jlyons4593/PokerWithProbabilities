#include "OddsView.h"
#include <iostream>
#include "HandEvaluator.h"
void OddsView::initVariables()
{
	this->isGameRunning = true;
	this->font.loadFromFile("Fonts/Roboto-Black.ttf");
}
void OddsView::initialiseWindow()
{
	this->videomode.height = 720;
	this->videomode.width = 1280;

	this->window = new sf::RenderWindow(this->videomode, "Poker&Probabilities", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void OddsView::initialiseMenuBar()
{
	
	this->setRectangleProperties(this->menuBar, sf::Vector2f(this->videomode.width, 250.f), sf::Vector2f(this->videomode.width / 2, 0), sf::Color::Black);
	this->setTextProperties(this->title, "Poker & Probability", sf::Vector2f(this->videomode.width / 2, 70.f), int(this->videomode.width / 25), sf::Color::White);
	
	
	
}

void OddsView::initialisePlayerCards()
{

	setCardProperties(this->player_card1_sprite, deck.currentDeck[this->player_card1.index].cardFace, 1.5f, sf::Vector2f((this->videomode.width / 2) - 40.f, 500.f));
	setCardProperties(this->player_card2_sprite, deck.currentDeck[this->player_card2.index].cardFace, 1.5f, sf::Vector2f((this->videomode.width / 2) + 40.f, 500.f));
}

void OddsView::initialiseCommunityCards()
{
	
	if (community_card1.index == -1) {
		setCardProperties(this->community_card1_sprite, deck.backOfCardTexture, 1.5f, sf::Vector2f(static_cast<float>((this->videomode.width / 2) - 2 * (this->videomode.width / 10)), 270.f));

		setCardProperties(this->community_card2_sprite, deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) - (this->videomode.width / 10), 270.f));

		setCardProperties(this->community_card3_sprite, deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2), 270.f));

	}
	else {
		setCardProperties(this->community_card1_sprite, deck.currentDeck[this->community_card1.index].cardFace, 1.5f, sf::Vector2f(static_cast<float>((this->videomode.width / 2) - 2 * (this->videomode.width / 10)), 270.f));

		setCardProperties(this->community_card2_sprite, deck.currentDeck[this->community_card2.index].cardFace, 1.5f, sf::Vector2f((this->videomode.width / 2) - (this->videomode.width / 10), 270.f));

		setCardProperties(this->community_card3_sprite, deck.currentDeck[this->community_card3.index].cardFace, 1.5f, sf::Vector2f((this->videomode.width / 2), 270.f));
	}
	
	if (community_card4.index == -1) {
		setCardProperties(this->community_card4_sprite, deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) + (this->videomode.width / 10), 270.f));

	}
	else {
		setCardProperties(this->community_card4_sprite, deck.currentDeck[this->community_card4.index].cardFace, 1.5f, sf::Vector2f((this->videomode.width / 2) + (this->videomode.width / 10), 270.f));

	}
	if (community_card5.index == -1) {
		setCardProperties(this->community_card5_sprite, deck.backOfCardTexture, 1.5f, sf::Vector2f((this->videomode.width / 2) + 2*(this->videomode.width / 10), 270.f));

	}
	else {
		setCardProperties(this->community_card5_sprite, deck.currentDeck[this->community_card5.index].cardFace, 1.5f, sf::Vector2f((this->videomode.width / 2) + 2*(this->videomode.width / 10), 270.f));

	}


}

void OddsView::initialiseOutsText()
{
	this->setTextProperties(this->outs_text_, "Outs", sf::Vector2f((this->videomode.width / 2) - 100.f, 600.f), int(this->videomode.width / 70), sf::Color::White);
	this->setTextProperties(this->outs_value_text_, std::to_string(this->outs), sf::Vector2f((this->videomode.width / 2) - 100.f, 630.f), int(this->videomode.width / 70), sf::Color::White);
	
}

void OddsView::initialiseHandStrengthText()
{
	this->setTextProperties(this->hand_strength_text_, "Hand Strength", sf::Vector2f((this->videomode.width / 2) - 250.f, 450.f), int(this->videomode.width / 70), sf::Color::White);
	this->setTextProperties(this->hand_strength_value_text_, std::to_string(this->percentHands)+"%" , sf::Vector2f((this->videomode.width / 2) - 250.f, 480.f), int(this->videomode.width / 70), sf::Color::White);
}

void OddsView::initialisePotOdds()
{
	this->setTextProperties(this->pot_odds_text_, "Pot Odds", sf::Vector2f((this->videomode.width / 2) + 100.f, 600.f), int(this->videomode.width / 70), sf::Color::White);
	this->setTextProperties(this->pot_odds_value_text_, std::to_string(int(this->potOdds))+ "%", sf::Vector2f((this->videomode.width / 2) + 100.f, 630.f), int(this->videomode.width / 70), sf::Color::White);
}

void OddsView::initialiseExpectedValue()
{
	this->setTextProperties(this->expected_value_text_, "Expected Vaue", sf::Vector2f((this->videomode.width / 2) + 250.f, 450.f), int(this->videomode.width / 70), sf::Color::White);
	this->setTextProperties(this->expected_value_value_text_, "+50", sf::Vector2f((this->videomode.width / 2) + 250.f, 480.f), int(this->videomode.width / 70), sf::Color::White);
}


void OddsView::processPlayerChoices()
{
}

void OddsView::renderGameObjects(sf::RenderTarget& target)
{
	
	target.draw(this->menuBar);
	target.draw(this->title);
	target.draw(this->closeButton);
	target.draw(this->closeText);
	target.draw(this->player_card1_sprite);
	target.draw(this->player_card2_sprite);
	target.draw(this->community_card1_sprite);
	target.draw(this->community_card2_sprite);
	target.draw(this->community_card3_sprite);
	target.draw(this->community_card4_sprite);
	target.draw(this->community_card5_sprite);

	target.draw(this->outs_text_);
	target.draw(this->outs_value_text_);
	target.draw(this->expected_value_text_);
	target.draw(this->expected_value_value_text_);
	target.draw(this->hand_strength_text_);
	target.draw(this->hand_strength_value_text_);
	target.draw(this->pot_odds_text_);
	target.draw(this->pot_odds_value_text_);
	
	

}

void OddsView::calculatePotOdds()
{
	if (this->pot == 0) { return; }
	std::cout << this->pot << std::endl;
	std::cout << 10.0 / this->pot << std::endl;
	std::cout << (10.0 / this->pot)*100 << std::endl;
	float x = 10.0 / this->pot;
	this->potOdds = x*100;
	std::cout << this->potOdds;
	this->pot_odds_value_text_.setString(std::to_string(int(this->potOdds)) + "%");
}

void OddsView::combineCards()
{
	this->playerCards.clear();
	this->communityCards.clear();

	this->playerCards.push_back(player_card1);
	this->playerCards.push_back(player_card2);

	
	this->playerCards.push_back(community_card1);
	this->playerCards.push_back(community_card2);
	this->playerCards.push_back(community_card3);

	if (community_card4.index != -1) {
		this->playerCards.push_back(community_card4);
		
	}
	if (community_card5.index != -1) {
		this->playerCards.push_back(community_card5);

	}
	
}

void OddsView::setCurrentHandStrength()
{
	/*this->combineCards();
	std::vector<float> metrics =this->calculateHandStrength(this->playerCards, this->communityCards);
	this->relativeHandStrength = metrics[0];
	this->percentHands = metrics[0];*/
}


void OddsView::calculateHandStrength()
{
	this->combineCards();

	if (HandEvaluator::isStraightFlush(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 8;
		this->percentHands = 0;
		this->outs = 0;
	}
	else if (HandEvaluator::isFourOfAKind(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 7;
		this->percentHands = 0.0311;
		this->outs = 0;
	}
	else if (HandEvaluator::isFullHouse(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 6;
		this->percentHands = 0.199;
		this->outs = 1; 
	}
	else if (HandEvaluator::isFlush(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 5;
		this->percentHands = 2.8;
		this->outs = 3;
	}
	else if (HandEvaluator::isStraight(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 4;
		this->percentHands = 5.82;
		this->outs = 3;
	}
	else if (HandEvaluator::isThreeOfAKind(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 3;
		this->percentHands = 10.4;
		this->outs = 6;
	}
	else if (HandEvaluator::isTwoPair(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 2;
		this->percentHands = 15.3;
		this->outs = 10;
	}
	else if (HandEvaluator::isPair(this->playerCards, this->communityCards)) {
		this->relativeHandStrength = 1;
		this->percentHands = 38.8;
		this->outs = 33;
	}
	else {
		this->relativeHandStrength = 1;
		this->percentHands = 82.6;
		this->outs = 42;
	}
	/*std::vector<float> metrics = { (float)this->relativeHandStrength, this->percentHands };
	return metrics;*/
}

void OddsView::calculateExpectedValue()
{
	float winProbability = (100 - this->percentHands)/100;
	this->expectedValue = ((winProbability)*(this->pot + 20)) - ((1-winProbability)*20);
}


//void OddsView::calculateOuts()
//{
	/*this->outs = 0;
	std::vector<int> indices = {player_card1.index, player_card2.index };
	if (community_card1.index != -1) {
		indices.push_back(community_card1.index);
		indices.push_back(community_card2.index);
		indices.push_back(community_card3.index);
	}
	if (community_card4.index != -1) {
		indices.push_back(community_card4.index);
	}
	if (community_card5.index != -1) {
		indices.push_back(community_card5.index);
	}
	
	std::vector<Card> updatedDeck;
	for (const Card& card : outsDeck.currentDeck) {
		if (std::find(indices.begin(), indices.end(), card.index) == indices.end()) {
			updatedDeck.push_back(card);
		}
	}

	outsDeck.currentDeck= std::move(updatedDeck);

	for (auto& card : outsDeck.currentDeck) {
		std::vector<Card> possibleCommunityCards = this->communityCards;
		possibleCommunityCards.push_back(card);
		std::vector<float> metrics = this->calculateHandStrength(this->playerCards, possibleCommunityCards);
		if (metrics[0] > this->relativeHandStrength) {
			this->outs++;
		}

	}*/

//}

void OddsView::startGame()
{
}

void OddsView::loseGame()
{
}

void OddsView::winGame()
{
}


void OddsView::setPlayer(Player* player)
{
}

void OddsView::updateOnBet()
{
}

void OddsView::updateCommunityCardsOnFlop(Card& c1, Card& c2, Card& c3)
{
	this->community_card1 = c1;
	this->community_card1_sprite.setTexture(this->deck.currentDeck[c1.index].cardFace);
	this->community_card2 = c2;
	this->community_card2_sprite.setTexture(this->deck.currentDeck[c2.index].cardFace);
	this->community_card3 = c3;
	this->community_card3_sprite.setTexture(this->deck.currentDeck[c3.index].cardFace);
	this->calculateHandStrength();
	this->hand_strength_value_text_.setString(std::to_string(this->percentHands) + "%");
	this->calculateExpectedValue();
	this->expected_value_value_text_.setString(std::to_string(this->expectedValue));
	
	this->outs_value_text_.setString(std::to_string(this->outs));
}

void OddsView::updateCommunityCardsOnTurn(Card& card)
{
	this->community_card4 = card;
	this->community_card4_sprite.setTexture(this->deck.currentDeck[card.index].cardFace);

	this->calculateHandStrength();
	this->hand_strength_value_text_.setString(std::to_string(this->percentHands) + "%");
	//this->calculateOuts();
	this->outs_value_text_.setString(std::to_string(this->outs));
	this->calculateExpectedValue();
	this->expected_value_value_text_.setString(std::to_string(this->expectedValue));
}

void OddsView::updateCommunityCardsOnRiver(Card& card)
{
	this->community_card5 = card;
	this->community_card5_sprite.setTexture(this->deck.currentDeck[card.index].cardFace);
	this->calculateHandStrength();
	this->hand_strength_value_text_.setString(std::to_string(this->percentHands) + "%");
	this->calculateExpectedValue();
	this->expected_value_value_text_.setString(std::to_string(this->expectedValue));
	//this->outs_value_text_.setString("0");

}

void OddsView::updateShowdown(std::vector<Card> aiCards, std::vector<Card> ai2Cards, std::vector<Card> ai3Cards, int winner)
{
}

void OddsView::updatePlayerCards(std::vector<Card> cards)
{
	this->player_card1 = cards[0];
	this->player_card1_sprite.setTexture(this->deck.currentDeck[cards[0].index].cardFace);

	this->player_card2 = cards[1];
	this->player_card2_sprite.setTexture(this->deck.currentDeck[cards[1].index].cardFace);


	

}

void OddsView::foldPlayer(int playerIndex)
{
}

void OddsView::callPlayer(int playerIndex, int chipAmount)
{
}

void OddsView::checkPlayer(int playerIndex)
{
}

void OddsView::allInPlayer(int playerIndex)
{
}

void OddsView::raisePlayer(int playerIndex, int raiseAmount)
{
}

void OddsView::updatePot(int pot)
{
	this->pot = pot;
	this->calculatePotOdds();
	//this->calculateHandStrength();
}

void OddsView::update()
{
	this->pollEvents();

	// Update mouse positions
	this->updateMousePositions();

	this->processPlayerChoices();


}


void OddsView::render()
{
	this->window->clear(sf::Color(0, 100, 0));


	this->renderGameObjects(*this->window);


	this->window->display();
}

void OddsView::init() 
{
	this->initVariables();
	this->initialiseWindow();
	this->initialiseMenuBar();
	this->initialisePlayerCards();
	this->initialiseCommunityCards();
	this->initialiseOutsText();
	this->initialisePotOdds();
	this->initialiseHandStrengthText();
	this->initialiseExpectedValue();
}

OddsView::OddsView()
{
	this->outs = 50;
	this->potOdds = 100;
	player_card1.cardFace = deck.backOfCardTexture;
	player_card2.cardFace = deck.backOfCardTexture;

	community_card1.index = -1;
	community_card2.index = -1;
	community_card3.index = -1;
	community_card4.index = -1;
	community_card5.index = -1;
	
	




}

OddsView::~OddsView()
{
	delete this->window;
}