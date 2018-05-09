#include "LegendaryFish.h"


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
	type = Type::LEGENDARY;
	randomizeFish(random);
}

LegendaryFish::~LegendaryFish()
{
}
