#include "Field.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include "Chance.h"
#include "FishFactory.h"
#include <chrono>
#include <iostream>

std::function<bool(Fish*)> Field::callback;

Field::Field(sf::Vector2f position):
	timeElapsed(0),
	stopUpdate(true)
{
	sf::Texture &texture = Loader::getInstance().getTexture(Loader::Type::water);
	body.setTexture(texture);
	color = sf::Color(255, 255, 255);
	body.setPosition(position);
}

bool Field::stopUpdating()
{
	return stopUpdate;
}

inline void Field::setFadingSpeed()
{
	fadingSpeed = 255000 / fish->getDuration().count();
}

void Field::update(const us & dt)
{
	fade(dt);
	timeElapsed += dt;
	if (timeElapsed >= fish->getDuration())
		reset();
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
	fish = std::shared_ptr<Fish>(FishFactory::createFish(random));
	setFadingSpeed();
	stopUpdate = false;
}

Fish & Field::getFish()
{
	return *fish.get();
}

bool Field::onClick()
{
	if (fish.get()) {
		callback(fish.get());
		reset();
	}
	else
		callback(NULL);
	return false;
}

void Field::setCallback(std::function<bool(Fish*)> func)
{
	callback = func;
}

void Field::reset()
{
	body.setColor(sf::Color(255,255,255));
	timeElapsed = timeElapsed.zero();
	fish.reset();
	stopUpdate = true;
}

Field::~Field()
{

}
