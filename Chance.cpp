#include "Chance.h"
#include <chrono>
#include <stdint.h>
#include <iostream>

long long int Chance::defaultSeed = 
	std::chrono::system_clock::to_time_t(
		std::chrono::time_point_cast<std::chrono::microseconds>(
			std::chrono::system_clock::now()))
				/10000;

Chance::Chance(int min, int offset) :
	min(min),
	offset(offset),
	seed(defaultSeed)
{
}

Chance::Chance(long long int &seed, int min, int offset) :
	min(min),
	offset(offset),
	seed(seed)
{
}

Chance::~Chance()
{
}

long long int Chance::getRandomValue() {
	return engine() % offset + min;
}

long long int Chance::getRandomValue(int min, int offset)
{
	return engine() % offset + min;
}

void Chance::setSeed(long long int &seed)
{
	engine.seed(seed);
}

void Chance::setRange(int min, int offset)
{
	this->min = min;
	this->offset = offset;
}