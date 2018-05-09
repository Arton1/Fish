#include "CommonFish.h"


void CommonFish::setCost(Chance & random)
{
	cost = 1;
}

void CommonFish::setDuration(Chance & random)
{
	duration = std::chrono::milliseconds(2000);
}

CommonFish::CommonFish(Chance & random)
{
	type = Type::COMMON;
	randomizeFish(random);
}


CommonFish::~CommonFish()
{
}
