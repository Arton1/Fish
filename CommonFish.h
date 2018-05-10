#pragma once
#include "Fish.h"

class CommonFish : public Fish
{
public:
	std::string getTypeString();
	void setCost(Chance &random) override;
	void setDuration(Chance &random) override;
	CommonFish(Chance &random);
	~CommonFish();
};

