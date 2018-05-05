#include "Field.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include <iostream>

Field::Field(sf::Vector2f position):
	timeElapsed(0),
	duration(1) 
{
	sf::Texture &texture = Loader::getInstance().getTexture(Loader::Type::water);
	body.setTexture(texture);
	color = sf::Color(255, 255, 255);
	body.getColor();
	body.setPosition(position);
	fadingSpeed = 255 / duration; //points per sec
}


void Field::fade(double dt)
{
	timeElapsed += dt/1000000; //seconds
	color.g = 255 - timeElapsed*fadingSpeed;
	color.b = 255 - timeElapsed*fadingSpeed;
	std::cout << timeElapsed << std::endl;
	body.setColor(color);
}

Field::~Field()
{

}
