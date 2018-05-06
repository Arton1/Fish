#include "Field.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include <chrono>
#include <iostream>

Field::Field(sf::Vector2f position):
	timeElapsed(0),
	duration(2) 
{
	sf::Texture &texture = Loader::getInstance().getTexture(Loader::Type::water);
	body.setTexture(texture);
	color = sf::Color(255, 255, 255);
	body.getColor();
	body.setPosition(position);
	fadingSpeed = 255 / duration; //points per sec
}


bool Field::update(const std::chrono::microseconds & dt)
{
	fade(dt);
	timeElapsed += (double)dt.count() / 1000000; //seconds
	if (timeElapsed >= duration) {
		reset();
		return true;
	}
	return false;
}

void Field::fade(const std::chrono::microseconds &dt)
{
	color.g = 255 - timeElapsed*fadingSpeed;
	color.b = 255 - timeElapsed*fadingSpeed;
	body.setColor(color);
}

void Field::reset()
{
	body.setColor(sf::Color(255,255,255));
	timeElapsed = 0;
}

Field::~Field()
{

}
