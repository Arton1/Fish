#pragma once

class Fish;
class Chance;

class FishFactory
{
public:
	static Fish* createFish(Chance &random);
	FishFactory() {};
	~FishFactory() {};
};

