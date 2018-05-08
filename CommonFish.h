#pragma once
#include "Fish.h"
class CommonFish : public Fish
{
public:
	void setCost(Chance &random) override;
	CommonFish(Chance &random);
	~CommonFish();
};

