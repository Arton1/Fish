#include "CommonFish.h"


void CommonFish::setCost(Chance & random)
{
	cost = 1;
}

CommonFish::CommonFish(Chance & random)
{
	type = Type::COMMON;
	randomizeFish(random);
}


CommonFish::~CommonFish()
{
}
