#ifndef ODDSVIEW_H
#define ODDSVIEW_H
#pragma once
#include "UI.h"
#include "Deck.h"
#include "ObserverPattern.cpp"
#include "Player.h"



class OddsView: public UI, public Observer
{
private:


	Deck deck;

	sf::Text winningText;

	sf::Text playAgainText;
	sf::RectangleShape playAgainButton;

	sf::Text title;
	sf::Text closeText;

	sf::RectangleShape closeButton;
	sf::RectangleShape menuBar;

	sf::Sprite player_card1_sprite;
	sf::Sprite player_card2_sprite;

	sf::Sprite community_card1_sprite;
	sf::Sprite community_card2_sprite;
	sf::Sprite community_card3_sprite;
	sf::Sprite community_card4_sprite;
	sf::Sprite community_card5_sprite;


	
	//Hand strength variables
	sf::Text hand_strength_text_;
	sf::Text hand_strength_value_text_;

	//Pot odds variables
	sf::Text pot_odds_text_;
	sf::Text pot_odds_value_text_;

	//Outs variables
	sf::Text outs_text_;
	sf::Text outs_value_text_;

	//Expected Value variables
	sf::Text expected_value_text_;
	sf::Text expected_value_value_text_;


	
	void initVariables();
	void initialiseWindow();
	void initialiseMenuBar();
	void initialisePlayerCards();
	void initialiseCommunityCards();
	void initialiseOutsText();
	void initialiseHandStrengthText();
	void initialisePotOdds();
	void initialiseExpectedValue();
	void processPlayerChoices();
	void renderGameObjects(sf::RenderTarget& target);


	//pot odds variables
	void calculatePotOdds();
	float potOdds;
	float pot;


	//handStrength variables
	std::vector<Card> playerCards;
	std::vector<Card> communityCards;
	void combineCards();
	void setCurrentHandStrength();
	void calculateHandStrength();
	int relativeHandStrength;
	float percentHands;
	
	// Outs variables 
	//void calculateOuts();
	//bool shouldRemove(const Card& card, const std::vector<int>& indicesToRemove);
	//Deck outsDeck;
	//int outs;

	// Expected value
	//void calculateExpectedValue();


	// player cards
	Card player_card1;
	Card player_card2;

	Card community_card1;
	Card community_card2;
	Card community_card3;
	Card community_card4;
	Card community_card5;
	
	

public:
	void startGame() override;
	void loseGame() override;
	void winGame() override;
	void setPlayer(Player* player)override;
	void updateOnBet()override;
	void updateCommunityCardsOnFlop(Card& c1, Card& c2, Card& c3) override;
	void updateCommunityCardsOnTurn(Card& card) override;
	void updateCommunityCardsOnRiver(Card& card) override;
	void updateShowdown(std::vector<Card> aiCards, std::vector<Card> ai2Cards, std::vector<Card> ai3Cards, int winner) override;
	// virtual void updatePlayerBettingAmount(int index, int bet);
	void updatePlayerCards(std::vector<Card> cards) override;
	void foldPlayer(int playerIndex) override;
	void callPlayer(int playerIndex, int chipAmount) override;
	void checkPlayer(int playerIndex) override;
	void allInPlayer(int playerIndex) override;
	void raisePlayer(int playerIndex, int raiseAmount) override;
	void updatePot(int pot) override;
	void update();
	void render();
	void init();
	OddsView();
	~OddsView();

};

#endif // ODDSVIEW_H