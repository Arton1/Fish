#include "Field.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include "Chance.h"
#include "FishFactory.h"
#include <chrono>
#include <iostream>

std::function<bool(Fish*)> Field::callback;

Field::Field(sf::Vector2f position):
	stopUpdate(true)
{
	sf::Texture &texture = Loader::getInstance().getTexture(Loader::Type::water);
	body.setTexture(texture);
	body.setPosition(position);
}

bool Field::stopUpdating()
{
	return stopUpdate;
}

void Field::update(const us & dt)
{
	fish->fade(dt);
	if (fish->disappeared())
		reset();
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
	fish->setPosition(body.getPosition());
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

void Field::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
	if(fish.get())
		target.draw(*fish);
}

void Field::reset()
{
	fish.reset();
	stopUpdate = true;
}

Field::~Field()
{

}
