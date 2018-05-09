#include "CommonFish.h"
#include "Chance.h"

std::string CommonFish::getTypeString()
{
	return "Common";
}

void CommonFish::setCost(Chance & random)
{
	cost = random.getRandomValue(1, 4);
}

void CommonFish::setDuration(Chance & random)
{
	int value = random.getRandomValue(1000, 1800);
	duration = std::chrono::milliseconds(value);
}

CommonFish::CommonFish(Chance & random):
	Fish(random)
{
	randomizeFish(random);
	setFadingSpeed();
	body.setTexture(Loader::getInstance().getTexture(Loader::Type::common));
}


CommonFish::~CommonFish()
{
}
