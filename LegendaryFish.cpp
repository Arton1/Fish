#include "LegendaryFish.h"


std::string LegendaryFish::getTypeString()
{
	return "Legend";
}

void LegendaryFish::setCost(Chance & random)
{
	cost = 100;
}

void LegendaryFish::setDuration(Chance & random)
{
	duration = std::chrono::milliseconds(400);
}

LegendaryFish::LegendaryFish(Chance &random)
{
	randomizeFish(random);
}

LegendaryFish::~LegendaryFish()
{
}
