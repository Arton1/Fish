#include "RareFish.h"


void RareFish::setCost(Chance & random)
{
	cost = 10;
}

RareFish::RareFish(Chance &random)
{
	type = Type::RARE;
	randomizeFish(random);
}


RareFish::~RareFish()
{
}
