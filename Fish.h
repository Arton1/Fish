#pragma once

class Chance;

class Fish
{
private:
	int cost;
public:
	int getCost();
	virtual void setCost(Chance &random) = 0;
	Fish();
	virtual ~Fish() = 0;
};

