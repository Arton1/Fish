#pragma once
#include "ClickableObject.h"
#include <chrono>

class Field : public ClickableObject
{
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::microseconds us;

	sf::Color color;
	us timeElapsed;
	ms duration;
	double fadingSpeed;
	bool fishInside;

	void reset();
public:
	Field(sf::Vector2f position);

	void setDuration(const ms &time);
	bool update(const us &dt); //returns true if have to stop updating
	void fade(const us &dt);
	bool isFishInside();
	~Field();
};

