#pragma once
#include "Fish.h"
class RareFish : public Fish
{
public:
	void setCost(Chance &random) override;
	RareFish();
	~RareFish();
};

