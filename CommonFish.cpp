#include "CommonFish.h"


std::string CommonFish::getTypeString()
{
	return "Common";
}

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
	randomizeFish(random);
}


CommonFish::~CommonFish()
{
}
