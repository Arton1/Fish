#include "RareFish.h"


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
	type = Type::RARE;
	randomizeFish(random);
}


RareFish::~RareFish()
{
}
