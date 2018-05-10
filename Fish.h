#pragma once
#include <chrono>
#include <string>
#include "Object.h"
#include "Loader.h"

typedef std::chrono::milliseconds ms;
typedef std::chrono::microseconds us;

class Chance;

class Fish : public Object
{
protected:

	int cost;

	ms duration;
	double fadingSpeed;
	us timeElapsed;
	int alpha;
public:
	Fish(Chance &random);
	int getCost();
	virtual std::string getTypeString() = 0;
	ms getDuration();
	virtual void setCost(Chance &random) = 0;
	virtual void setDuration(Chance &random) = 0;
	virtual void randomizeFish(Chance &random);
	void setFadingSpeed();
	void fade(const us &dt);
	bool disappeared();
	void setPosition(sf::Vector2f position);
	virtual ~Fish() = 0;
};

