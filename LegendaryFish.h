#pragma once
#include "Fish.h"
class LegendaryFish : public Fish
{
public:
	std::string getTypeString();
	void setCost(Chance &random) override;
	void setDuration(Chance &random) override;
	LegendaryFish(Chance &random);
	~LegendaryFish();
};