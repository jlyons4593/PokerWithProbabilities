#include "Deck.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <array>




void Deck::loadCardTextures()
{

	//Card Back

	
	this->backOfCardTexture.loadFromFile("Resources/card_back.png");
	

	//CLUBS

	std::array<std::string, 52> fileNames = {
	"card_clubs_A.png", "card_clubs_02.png", "card_clubs_03.png",
	"card_clubs_04.png", "card_clubs_05.png", "card_clubs_06.png",
	"card_clubs_07.png", "card_clubs_08.png", "card_clubs_09.png",
	"card_clubs_10.png", "card_clubs_J.png", "card_clubs_Q.png",
	"card_clubs_K.png",
	"card_spades_A.png", "card_spades_02.png", "card_spades_03.png",
	"card_spades_04.png", "card_spades_05.png", "card_spades_06.png",
	"card_spades_07.png", "card_spades_08.png", "card_spades_09.png",
	"card_spades_10.png", "card_spades_J.png", "card_spades_Q.png",
	"card_spades_K.png",
	"card_hearts_A.png", "card_hearts_02.png", "card_hearts_03.png",
	"card_hearts_04.png", "card_hearts_05.png", "card_hearts_06.png",
	"card_hearts_07.png", "card_hearts_08.png", "card_hearts_09.png",
	"card_hearts_10.png", "card_hearts_J.png", "card_hearts_Q.png",
	"card_hearts_K.png",
	"card_diamonds_A.png", "card_diamonds_02.png", "card_diamonds_03.png",
	"card_diamonds_04.png", "card_diamonds_05.png", "card_diamonds_06.png",
	"card_diamonds_07.png", "card_diamonds_08.png", "card_diamonds_09.png",
	"card_diamonds_10.png", "card_diamonds_J.png", "card_diamonds_Q.png",
	"card_diamonds_K.png"
	};

	for (const auto& fileName : fileNames) {
		sf::Texture texture;
		texture.loadFromFile("Resources/" + fileName);
		Deck::cardFaces.push_back(texture);
	}

	//sf::Texture textureAceOfClubs;
	//textureAceOfClubs.loadFromFile("Resources/card_clubs_A.png");
	//Deck::cardFaces.push_back(textureAceOfClubs);

	//sf::Texture texture2OfClubs;
	//texture2OfClubs.loadFromFile("Resources/card_clubs_02.png");
	//Deck::cardFaces.push_back(texture2OfClubs);

	//sf::Texture texture3OfClubs;
	//texture3OfClubs.loadFromFile("Resources/card_clubs_03.png");
	//Deck::cardFaces.push_back(texture3OfClubs);

	//sf::Texture texture4OfClubs;
	//texture4OfClubs.loadFromFile("Resources/card_clubs_04.png");
	//Deck::cardFaces.push_back(texture4OfClubs);

	//sf::Texture texture5OfClubs;
	//texture5OfClubs.loadFromFile("Resources/card_clubs_05.png");
	//Deck::cardFaces.push_back(texture5OfClubs);

	//sf::Texture texture6OfClubs;
	//texture6OfClubs.loadFromFile("Resources/card_clubs_06.png");
	//Deck::cardFaces.push_back(texture6OfClubs);

	//sf::Texture texture7OfClubs;
	//texture7OfClubs.loadFromFile("Resources/card_clubs_07.png");
	//Deck::cardFaces.push_back(texture7OfClubs);

	//sf::Texture texture8OfClubs;
	//texture8OfClubs.loadFromFile("Resources/card_clubs_08.png");
	//Deck::cardFaces.push_back(texture8OfClubs);

	//sf::Texture texture9OfClubs;
	//texture9OfClubs.loadFromFile("Resources/card_clubs_09.png");
	//Deck::cardFaces.push_back(texture9OfClubs);

	//sf::Texture texture10OfClubs;
	//texture10OfClubs.loadFromFile("Resources/card_clubs_10.png");
	//Deck::cardFaces.push_back(texture10OfClubs);

	//sf::Texture textureJackOfClubs;
	//textureJackOfClubs.loadFromFile("Resources/card_clubs_J.png");
	//Deck::cardFaces.push_back(textureJackOfClubs);

	//sf::Texture textureQueenOfClubs;
	//textureQueenOfClubs.loadFromFile("Resources/card_clubs_Q.png");
	//Deck::cardFaces.push_back(textureQueenOfClubs);

	//sf::Texture textureKingOfClubs;
	//textureKingOfClubs.loadFromFile("Resources/card_clubs_K.png");
	//Deck::cardFaces.push_back(textureKingOfClubs);

	//////SPADES

	//sf::Texture textureAceOfSpades;
	//textureAceOfSpades.loadFromFile("Resources/card_spades_A.png");
	//Deck::cardFaces.push_back(textureAceOfSpades);

	//sf::Texture texture2OfSpades;
	//texture2OfSpades.loadFromFile("Resources/card_spades_02.png");
	//Deck::cardFaces.push_back(texture2OfSpades);

	//sf::Texture texture3OfSpades;
	//texture3OfSpades.loadFromFile("Resources/card_spades_03.png");
	//Deck::cardFaces.push_back(texture3OfSpades);

	//sf::Texture texture4OfSpades;
	//texture4OfSpades.loadFromFile("Resources/card_spades_04.png");
	//Deck::cardFaces.push_back(texture4OfSpades);

	//sf::Texture texture5OfSpades;
	//texture5OfSpades.loadFromFile("Resources/card_spades_05.png");
	//Deck::cardFaces.push_back(texture5OfSpades);

	//sf::Texture texture6OfSpades;
	//texture6OfSpades.loadFromFile("Resources/card_spades_06.png");
	//Deck::cardFaces.push_back(texture6OfSpades);

	//sf::Texture texture7OfSpades;
	//texture7OfSpades.loadFromFile("Resources/card_spades_07.png");
	//Deck::cardFaces.push_back(texture7OfSpades);

	//sf::Texture texture8OfSpades;
	//texture8OfSpades.loadFromFile("Resources/card_spades_08.png");
	//Deck::cardFaces.push_back(texture8OfSpades);

	//sf::Texture texture9OfSpades;
	//texture9OfSpades.loadFromFile("Resources/card_spades_09.png");
	//Deck::cardFaces.push_back(texture9OfSpades);

	//sf::Texture texture10OfSpades;
	//texture10OfSpades.loadFromFile("Resources/card_spades_10.png");
	//Deck::cardFaces.push_back(texture10OfSpades);

	//sf::Texture textureJackOfSpades;
	//textureJackOfSpades.loadFromFile("Resources/card_spades_J.png");
	//Deck::cardFaces.push_back(textureJackOfSpades);

	//sf::Texture textureQueenOfSpades;
	//textureQueenOfSpades.loadFromFile("Resources/card_spades_Q.png");
	//Deck::cardFaces.push_back(textureQueenOfSpades);

	//sf::Texture textureKingOfSpades;
	//textureKingOfSpades.loadFromFile("Resources/card_spades_K.png");
	//Deck::cardFaces.push_back(textureKingOfSpades);

	//////Diamonds

	//sf::Texture textureAceOfDiamonds;
	//textureAceOfDiamonds.loadFromFile("Resources/card_diamonds_A.png");
	//Deck::cardFaces.push_back(textureAceOfDiamonds);

	//sf::Texture texture2OfDiamonds;
	//texture2OfDiamonds.loadFromFile("Resources/card_diamonds_02.png");
	//Deck::cardFaces.push_back(texture2OfDiamonds);

	//sf::Texture texture3OfDiamonds;
	//texture3OfDiamonds.loadFromFile("Resources/card_diamonds_03.png");
	//Deck::cardFaces.push_back(texture3OfDiamonds);

	//sf::Texture texture4OfDiamonds;
	//texture4OfDiamonds.loadFromFile("Resources/card_diamonds_04.png");
	//Deck::cardFaces.push_back(texture4OfDiamonds);

	//sf::Texture texture5OfDiamonds;
	//texture5OfDiamonds.loadFromFile("Resources/card_diamonds_05.png");
	//Deck::cardFaces.push_back(texture5OfDiamonds);

	//sf::Texture texture6OfDiamonds;
	//texture6OfDiamonds.loadFromFile("Resources/card_diamonds_06.png");
	//Deck::cardFaces.push_back(texture6OfDiamonds);

	//sf::Texture texture7OfDiamonds;
	//texture7OfDiamonds.loadFromFile("Resources/card_diamonds_07.png");
	//Deck::cardFaces.push_back(texture7OfDiamonds);

	//sf::Texture texture8OfDiamonds;
	//texture8OfDiamonds.loadFromFile("Resources/card_diamonds_08.png");
	//Deck::cardFaces.push_back(texture8OfDiamonds);

	//sf::Texture texture9OfDiamonds;
	//texture9OfDiamonds.loadFromFile("Resources/card_diamonds_09.png");
	//Deck::cardFaces.push_back(texture9OfDiamonds);

	//sf::Texture texture10OfDiamonds;
	//texture10OfDiamonds.loadFromFile("Resources/card_diamonds_10.png");
	//Deck::cardFaces.push_back(texture10OfDiamonds);

	//sf::Texture textureJackOfDiamonds;
	//textureJackOfDiamonds.loadFromFile("Resources/card_diamonds_J.png");
	//Deck::cardFaces.push_back(textureJackOfDiamonds);

	//sf::Texture textureQueenOfDiamonds;
	//textureQueenOfDiamonds.loadFromFile("Resources/card_diamonds_Q.png");
	//Deck::cardFaces.push_back(textureQueenOfDiamonds);

	//sf::Texture textureKingOfDiamonds;
	//textureKingOfDiamonds.loadFromFile("Resources/card_diamonds_K.png");
	//Deck::cardFaces.push_back(textureKingOfDiamonds);

	//////HEARTS


	//sf::Texture textureAceOfHearts;
	//textureAceOfHearts.loadFromFile("Resources/card_hearts_A.png");
	//Deck::cardFaces.push_back(textureAceOfHearts);

	//sf::Texture texture2OfHearts;					
	//texture2OfHearts.loadFromFile("Resources/card_hearts_02.png");
	//Deck::cardFaces.push_back(texture2OfHearts);

	//sf::Texture texture3OfHearts;					
	//texture3OfHearts.loadFromFile("Resources/card_hearts_03.png");
	//Deck::cardFaces.push_back(texture3OfHearts);

	//sf::Texture texture4OfHearts;					
	//texture4OfHearts.loadFromFile("Resources/card_hearts_04.png");
	//Deck::cardFaces.push_back(texture4OfHearts);

	//sf::Texture texture5OfHearts;					
	//texture5OfHearts.loadFromFile("Resources/card_hearts_05.png");
	//Deck::cardFaces.push_back(texture5OfHearts);

	//sf::Texture texture6OfHearts;					
	//texture6OfHearts.loadFromFile("Resources/card_hearts_06.png");
	//Deck::cardFaces.push_back(texture6OfHearts);

	//sf::Texture texture7OfHearts;					
	//texture7OfHearts.loadFromFile("Resources/card_hearts_07.png");
	//Deck::cardFaces.push_back(texture7OfHearts);

	//sf::Texture texture8OfHearts;					
	//texture8OfHearts.loadFromFile("Resources/card_hearts_08.png");
	//Deck::cardFaces.push_back(texture8OfHearts);

	//sf::Texture texture9OfHearts;					
	//texture9OfHearts.loadFromFile("Resources/card_hearts_09.png");
	//Deck::cardFaces.push_back(texture9OfHearts);

	//sf::Texture texture10OfHearts;					
	//texture10OfHearts.loadFromFile("Resources/card_hearts_10.png");
	//Deck::cardFaces.push_back(texture10OfHearts);

	//sf::Texture textureJackOfHearts;				
	//textureJackOfHearts.loadFromFile("Resources/card_hearts_J.png");
	//Deck::cardFaces.push_back(textureJackOfHearts);

	//sf::Texture textureQueenOfHearts;				
	//textureQueenOfHearts.loadFromFile("Resources/card_hearts_Q.png");
	//Deck::cardFaces.push_back(textureQueenOfHearts);

	//sf::Texture textureKingOfHearts;				
	//textureKingOfHearts.loadFromFile("Resources/card_hearts_K.png");
	//Deck::cardFaces.push_back(textureKingOfHearts);
}


void Deck::initialiseDeck()
{
	this->loadCardTextures();
	int counter = 0;
	for (int i = (int)Suit::Clubs; i <= (int)Suit::Hearts;i++) 
	{
		for (int j = (int)CardValue::Ace; j <= (int)CardValue::King;j++) 
		{
			Card c;
			c.suit = (Suit)i;
			c.value = (CardValue)j;
			
			c.cardFace = Deck::cardFaces[counter];
			Deck::currentDeck.push_back(c);

			counter++;
			
		}
	}
}

Card Deck::drawCard()
{
	if (!Deck::currentDeck.empty())
	{
		Card c = Deck::currentDeck.back();
		Deck::currentDeck.pop_back();
		return c;
	}
	else
	{
		Card card;
		return card;
	}
}

void Deck::shuffleDeck()
{
	std::random_device rd;
	std::mt19937 g(rd());
	shuffle(Deck::currentDeck.begin(), Deck::currentDeck.end(), g);
}

Deck::Deck()
{
	this->initialiseDeck();
}
Deck::~Deck()
{
	
}