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

std::chrono::milliseconds Fish::getDuration()
{
	return duration;
}
