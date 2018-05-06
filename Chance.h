#pragma once
#include <random>

class Chance
{
	static long long int defaultSeed;
	long long int seed;
	int min, max;
	std::mt19937 engine;
public:
	void setSeed(long long int &seed);
	void setRange(int min, int max);

	Chance(int min, int max);
	long long int getRandomValue();
	long long int getRandomValue(int min, int max);
	Chance(long long int &seed, int min, int max);
	~Chance();
};

