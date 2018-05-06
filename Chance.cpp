#include "Chance.h"
#include <chrono>
#include <stdint.h>
#include <iostream>

long long int Chance::defaultSeed = 
	std::chrono::system_clock::to_time_t(
		std::chrono::time_point_cast<std::chrono::microseconds>(
			std::chrono::system_clock::now()))
				/10000;

Chance::Chance(int min, int max) :
	min(min),
	max(max),
	seed(defaultSeed)
{
}

Chance::Chance(long long int &seed, int min, int max) :
	min(min),
	max(max),
	seed(seed)
{
}

Chance::~Chance()
{
}

long long int Chance::getRandomValue() {
	return (engine() + min) % max;
}

long long int Chance::getRandomValue(int min, int max)
{
	setRange(min, max);
	return getRandomValue();
}

void Chance::setSeed(long long int &seed)
{
	engine.seed(seed);
}

void Chance::setRange(int min, int max)
{
	this->min = min;
	this->max = max;
}