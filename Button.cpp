#include "Button.h"
#include <SFML\Graphics.hpp>
#include <iostream>

Button::Button()
{
	sf::Image image;
	image.create(200, 200);
	sf::Texture texture;
	texture.loadFromImage(image);
	body.setTexture(texture);
	body.setColor(sf::Color::Yellow);
	this->setState(State::NOTHING);
	onClick = ClickPtr::defaultClick;
	std::cout << "Created button" << std::endl;
}

Button::Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt, void (*onClickPtr)()) {
	sf::Image image;
	image.create(sizeX, sizeY);
	sf::Texture texture;
	texture.loadFromImage(image);
	body.setTexture(texture);
	body.setColor(color);
	body.setPosition(posX, posY);
	label = txt;
	this->setState(State::NOTHING);
	onClick = onClickPtr;
	std::cout << "Created button " + label  << std::endl;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(body);
}

int Button::getState()
{
	return state;
}

void Button::setState(State state)
{
	this->state = state;
}