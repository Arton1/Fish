#pragma once
#include <chrono>
#include <string>

class Chance;

class Fish
{
protected:
	int cost;
	std::chrono::milliseconds duration;
public:
	Fish();
	int getCost();
	virtual std::string getTypeString() = 0;
	std::chrono::milliseconds getDuration();
	virtual void setCost(Chance &random) = 0;
	virtual void setDuration(Chance &random) = 0;
	virtual void randomizeFish(Chance &random);
	virtual ~Fish() = 0;
};

