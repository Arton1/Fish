#pragma once
#include <random>

class Chance
{
	static long long int defaultSeed;
	long long int seed;
	int min, offset;
	std::mt19937 engine;
public:
	void setSeed(long long int &seed);
	void setRange(int min, int offset);

	Chance(int min, int offset);
	long long int getRandomValue();
	long long int getRandomValue(int min, int offset);
	Chance(long long int &seed, int min, int offset);
	~Chance();
};

