#pragma once
class Fish
{
public:
	enum Type {common, rare, epic};
private:
	Type type;
	int cost;
public:
	int getCost();
	Type getType();
	Fish();
	~Fish();
};

