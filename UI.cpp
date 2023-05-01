#include "UI.h"


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