#include "Button.h"
#include <iostream>

//Button::Button(int sizeX, int sizeY, int posX, int posY)
Button::Button()
{
	
	body.setSize(sf::Vector2f(200, 200));
	body.setPosition(300, 300);
	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::Black);
	body.setFillColor(sf::Color::Blue);
	std::cout << "Created button" << std::endl;
}

Button::~Button()
{
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	std::cout << this->body.getPosition().x << std::endl;
	target.draw(body, states);
}