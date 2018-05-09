#include "LegendaryFish.h"
#include "Chance.h"

std::string LegendaryFish::getTypeString()
{
	return "Legend";
}

void LegendaryFish::setCost(Chance & random)
{
	cost = random.getRandomValue(60, 200);
}

void LegendaryFish::setDuration(Chance & random)
{
	int value = random.getRandomValue(600, 1100);
	duration = std::chrono::milliseconds(value);
}

LegendaryFish::LegendaryFish(Chance &random):
	Fish(random)
{
	randomizeFish(random);
	setFadingSpeed();
	body.setTexture(Loader::getInstance().getTexture(Loader::Type::legendary));
}

LegendaryFish::~LegendaryFish()
{
}
