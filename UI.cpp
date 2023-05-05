#include "UI.h"



void UI::setRectangleProperties(sf::RectangleShape& rectangle, const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& fillColor)
{
	rectangle.setSize(size);
	rectangle.setFillColor(fillColor);
	sf::FloatRect bounds = rectangle.getLocalBounds();
	rectangle.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
	rectangle.setPosition(position);
}

void UI::setCardProperties(sf::Sprite& card, sf::Texture& texture, float scale, const sf::Vector2f& position, float rotation/* = 0 */)
{
	card.setTexture(texture);
	card.setScale(scale, scale);
	sf::FloatRect cardRectangle = card.getLocalBounds();
	card.setRotation(rotation);
	card.setOrigin(cardRectangle.left + round(cardRectangle.width / 2.0f), cardRectangle.top + round(cardRectangle.height / 2.0f));
	card.setPosition(position);
	

}




void UI::setTextProperties(sf::Text& text, const std::string& string, const sf::Vector2f& position, int characterSize, const sf::Color& fillColor)
{
	text.setString(string);
	text.setFillColor(fillColor);
	text.setFont(this->font);
	text.setCharacterSize(characterSize);
	sf::FloatRect rectangle = text.getLocalBounds();
	text.setOrigin(rectangle.left + round(rectangle.width / 2.0f), rectangle.top + round(rectangle.height / 2.0f));
	text.setPosition(position);
}

void UI::updateMousePositions()
{
	this->mousePositionInt = sf::Mouse::getPosition(*this->window);
	this->mousePositionFloat = this->window->mapPixelToCoords(this->mousePositionInt);
}

void UI::pollEvents()
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