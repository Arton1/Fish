#pragma once

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
public:
	Fish();
	int getCost();
	Type getType();
	virtual void setCost(Chance &random) = 0;
	virtual void randomizeFish(Chance &random);
	virtual ~Fish() = 0;
};

