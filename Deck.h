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
	int index;

};

// bool cardComparator(const Card& c1, const Card& c2) {
//     if (c1.suit < c2.suit) {
//         return true;
//     } else if (c1.suit == c2.suit) {
//         return c1.value < c2.value;
//     } else {
//         return false;
//     }
// }
// bool compareByCardValue(Card& c1, Card& c2){
// 	return c1.value < c2.value;
// }


struct Chip{
	int chipValue;
	std::string chipColor;
	sf::Texture chipImage;
};



class Deck
{
private:
	std::vector<sf::Texture> cardFaces;
	
	void loadCardTextures();
	void createChips();

public:

	//Constructor
	Deck();
	//Destructor
	~Deck();

	//blank Card
	sf::Texture backOfCardTexture;
	//Deck of cards
	std::vector<Card> currentDeck;

	std::vector<Chip> chipSet;

	//draw top card
	Card drawCard();

	//shuffle Deck

	void shuffleDeck();

	//load
	
	void initialiseDeck();
	
};
