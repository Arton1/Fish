#include "RareFish.h"


std::string RareFish::getTypeString()
{
	return "Rare";
}

void RareFish::setCost(Chance & random)
{
	cost = 10;
}

void RareFish::setDuration(Chance & random)
{
	duration = std::chrono::milliseconds(1000);
}

RareFish::RareFish(Chance &random)
{
	randomizeFish(random);
}


RareFish::~RareFish()
{
}
