#pragma once
#include "Fish.h"
class LegendaryFish : public Fish
{
public:
	void setCost(Chance &random) override;
	LegendaryFish();
	~LegendaryFish();
};

