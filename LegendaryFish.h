#pragma once
#include "Fish.h"
class LegendaryFish : public Fish
{
public:
	void setCost(Chance &random) override;
	void setDuration(Chance &random) override;
	LegendaryFish(Chance &random);
	~LegendaryFish();
};