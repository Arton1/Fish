#include "Button.h"
#include <iostream>

Button::Button()
{
	body.setSize(sf::Vector2f(200, 200));
	body.setPosition(-300, -300);
	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::White);
	body.setFillColor(sf::Color::Red);
	setState(State::NOTHING);
	std::cout << "Created button" << std::endl;
}

Button::Button(int sizeX, int sizeY, int posX, int posY, sf::Color color, sf::String txt) {
	body.setSize(sf::Vector2f(sizeX, sizeY));
	body.setPosition(posX, posY);
	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::Black);
	body.setFillColor(color);
	std::cout << "Created button" << std::endl;
}

Button::~Button()
{
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(body);
}

bool Button::clicked(sf::Vector2f worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y)){
		setState(State::CLICKED);
		return true;
	}
	setState(State::NOTHING);
	return false;
}

int Button::getState()
{
	return state;
}



void Button::setState(State state)
{
	this->state = state;
}
