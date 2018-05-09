#pragma once
#include <chrono>

class Chance;

class Fish
{
public:
	enum Type {
		COMMON,
		RARE,
		LEGENDARY
	};
protected:
	Type type;
	int cost;
	std::chrono::milliseconds duration;
public:
	Fish();
	int getCost();
	Type getType();
	std::chrono::milliseconds getDuration();
	virtual void setCost(Chance &random) = 0;
	virtual void setDuration(Chance &random) = 0;
	virtual void randomizeFish(Chance &random);
	virtual ~Fish() = 0;
};

