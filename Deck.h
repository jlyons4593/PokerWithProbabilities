#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <algorithm>
#include <random>

enum class Suit
{
	Clubs,
	Spades,
	Diamonds,
	Hearts
};

enum class CardValue
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

struct Card
{
	CardValue value;
	Suit suit;
	sf::Texture cardFace;

};
class Deck
{
private:
	std::vector<sf::Texture> cardFaces;
	
	void loadCardTextures();
	

public:
	//blank Card
	sf::Texture backOfCardTexture;
	//Deck of cards
	std::vector<Card> currentDeck;

	//draw top card
	Card drawCard();

	//shuffle Deck
	void shuffleDeck();

	//load
	
	void initialiseDeck();
	
};

