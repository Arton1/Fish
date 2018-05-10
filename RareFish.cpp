#include "RareFish.h"
#include "Chance.h"

std::string RareFish::getTypeString()
{
	return "Rare";
}

void RareFish::setCost(Chance & random)
{
	cost = random.getRandomValue(7, 25);
}

void RareFish::setDuration(Chance & random)
{
	int value = random.getRandomValue(900, 1300);
	duration = std::chrono::milliseconds(value);
}

RareFish::RareFish(Chance &random):
	Fish(random)
{
	randomizeFish(random);
	setFadingSpeed();
	body.setTexture(Loader::getInstance().getTexture(Loader::Type::rare));
}


RareFish::~RareFish()
{
}
