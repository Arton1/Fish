#pragma once
#include "Fish.h"
class RareFish : public Fish
{
public:
	std::string getTypeString();
	void setCost(Chance &random) override;
	void setDuration(Chance &random) override;
	RareFish(Chance &random);
	~RareFish();
};

