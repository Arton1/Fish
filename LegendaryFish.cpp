#include "LegendaryFish.h"


void LegendaryFish::setCost(Chance & random)
{
	cost = 100;
}

LegendaryFish::LegendaryFish(Chance &random)
{
	type = Type::LEGENDARY;
	randomizeFish(random);
}

LegendaryFish::~LegendaryFish()
{
}
