#include "Button.h"
#include "State.h"
#include <SFML\Graphics.hpp>
#include <iostream>

sf::Font Button::font;

Button::Button()
{
	sf::Image image;
	image.create(200, 200);
	sf::Texture texture;
	texture.loadFromImage(image);
	body.setTexture(texture);
	body.setColor(sf::Color::Yellow);
	std::cout << "Created button" << std::endl;
}

bool Button::setFont(std::string location)
{
	return font.loadFromFile(location);
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(label);
}

Button::Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt) {
	sf::Image image;
	image.create(sizeX, sizeY);
	sf::Texture texture;
	texture.loadFromImage(image);
	body.setTexture(texture);
	body.setColor(color);
	body.setPosition(posX, posY);
	label.setFont(font);
	label.setString(txt);
	label.setPosition(getLabelPositionToSetTo());
}

sf::Vector2f Button::getLabelPositionToSetTo()
{
	sf::Vector2f position;
	position.x = body.getPosition().x + body.getTexture()->getSize().x/3;
	position.y = body.getPosition().y + body.getTexture()->getSize().y/3;
	return position;
}