#include "Fish.h"
#include "Chance.h"

Fish::Fish() {}

void Fish::randomizeFish(Chance & random)
{
	setCost(random);
}

Fish::~Fish() {}

int Fish::getCost()
{
	return cost;
}

Fish::Type Fish::getType()
{
	return type;
}
