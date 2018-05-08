#include "Field.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include "Chance.h"
#include <chrono>
#include <iostream>

Field::Field(sf::Vector2f position):
	timeElapsed(0),
	duration(1000)
{
	sf::Texture &texture = Loader::getInstance().getTexture(Loader::Type::water);
	body.setTexture(texture);
	color = sf::Color(255, 255, 255);
	body.setPosition(position);
	fadingSpeed = 255000 / duration.count(); //points per sec
}


void Field::setDuration(const ms &time)
{
	duration = time;
	fadingSpeed = 255000 / duration.count();
}

bool Field::update(const us & dt)
{
	fade(dt);
	timeElapsed += dt;
	if (timeElapsed >= duration) {
		reset();
		return true;
	}
	return false;
}

void Field::fade(const us &dt)
{
	color.g = 255 - (double)timeElapsed.count()*fadingSpeed/1000000;
	color.b = 255 - (double)timeElapsed.count()*fadingSpeed/1000000;
	body.setColor(color);
}

bool Field::isFishInside()
{
	if (fish.get())
		return true;
	else
		return false;
}

void Field::initialize(Chance & random)
{
	fish = std::shared_ptr<Fish>(new Fish(random));
	int time = random.getRandomValue(600, 1100);
	setDuration(std::chrono::milliseconds(time));
}

bool Field::onClick()
{
	if (fish.get())
		std::cout << fish->getType() << " " << fish->getCost() << std::endl;
	else
		std::cout << "Miss" << std::endl;
	return false;
}

void Field::reset()
{
	body.setColor(sf::Color(255,255,255));
	timeElapsed = timeElapsed.zero();
	fish.reset();
}

Field::~Field()
{

}
