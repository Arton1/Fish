#include "Button.h"
#include "State.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include <iostream>

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

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(label);
}

Button::Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt, std::function<void(void)> &callback) {
	sf::Image image;
	image.create(sizeX, sizeY);
	sf::Texture texture;
	texture.loadFromImage(image);
	body.setTexture(texture);
	body.setColor(color);
	body.setPosition(posX, posY);
	label.setFont(Loader::getInstance().getFont());
	label.setString(txt);
	label.setCharacterSize(30 * body.getTexture()->getSize().y / 100);
	label.setPosition(labelPositionToSetTo());
	label.setFillColor(sf::Color::Black);
	setCallback(callback);
}

sf::Vector2f Button::labelPositionToSetTo()
{
	sf::Vector2f position;
	int stringSize = label.getString().getSize();
	float characterXSize = label.getCharacterSize()*8/21;
	float characterYSize = label.getCharacterSize()*5/4;
	position.x = body.getPosition().x + body.getTexture()->getSize().x / 2 - characterXSize*stringSize/2;
	position.y = body.getPosition().y + body.getTexture()->getSize().y / 2 - characterYSize/2;
	return position;
}