#include "Fish.h"
#include "Chance.h"

Fish::Fish(Chance &random):
	alpha(255),
	timeElapsed(0)
{
}

void Fish::randomizeFish(Chance & random)
{
	setCost(random);
	setDuration(random);
}

void Fish::setFadingSpeed()
{
	fadingSpeed = 255000 / duration.count();
}

Fish::~Fish() {}

int Fish::getCost()
{
	return cost;
}

ms Fish::getDuration()
{
	return duration;
}


void Fish::fade(const us &dt)
{
	alpha = 255 - (double)timeElapsed.count()*fadingSpeed / 1000000;
	body.setColor(sf::Color(255, 255, 255, alpha));
	timeElapsed += dt;
}

bool Fish::disappeared()
{
	return timeElapsed >= duration;
}

void Fish::setPosition(sf::Vector2f position)
{
	body.setPosition(position.x + 5, position.y + 5);
}
