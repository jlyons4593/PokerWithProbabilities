#pragma once
#include <SFML/Graphics.hpp>

class UI
{
public:
	//mouse variables
	sf::Vector2i mousePositionInt;
	sf::Vector2f mousePositionFloat;
	bool lMBDown;

	// SFML Window variables
	sf::RenderWindow* window;
	sf::VideoMode videomode;

	// Font
	sf::Font font;
	
	// SFML Event variable
	sf::Event event;

	bool isGameRunning;

	// creating a drawable objects vector
	std::vector<std::shared_ptr<sf::Drawable>> drawables;

	
	void setTextProperties(sf::Text& text, const std::string& string, const sf::Vector2f& position, int characterSize, const sf::Color& fillColor /*= sf::Color::White*/);

	void setRectangleProperties(sf::RectangleShape& rectangle, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor);

	void setCardProperties(sf::Sprite& card, sf::Texture& texture, float scale, const sf::Vector2f& position, float rotation=0);
	
	
	void updateMousePositions();


	void virtual update() = 0;
	void virtual render() = 0;

	void pollEvents();


	
};

