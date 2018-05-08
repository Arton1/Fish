#pragma once
#include "ClickableObject.h"
#include <chrono>
#include "Fish.h"
#include <memory>

class Chance;

class Field : public ClickableObject
{
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::microseconds us;

	sf::Color color;
	us timeElapsed;
	ms duration;
	double fadingSpeed;
	std::shared_ptr<Fish> fish;

	void initialize(const Chance &chance);
	void reset();
public:
	Field(sf::Vector2f position);

	void setDuration(const ms &time);
	bool update(const us &dt); //returns true if have to stop updating
	void fade(const us &dt);
	bool isFishInside();
	~Field();
};

