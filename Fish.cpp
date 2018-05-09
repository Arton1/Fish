#include "Fish.h"
#include "Chance.h"

Fish::Fish() {}

void Fish::randomizeFish(Chance & random)
{
	setCost(random);
	setDuration(random);
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

std::chrono::milliseconds Fish::getDuration()
{
	return duration;
}
