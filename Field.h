#pragma once
#include "ClickableObject.h"
#include <chrono>
#include "Fish.h"
#include "FishFactory.h"
#include <memory>

class Chance;

class Field : public ClickableObject
{
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::microseconds us;

	sf::Color color;
	us timeElapsed;
	ms duration;
	bool stopUpdate;
	double fadingSpeed;
	std::shared_ptr<Fish> fish;
	void reset();
public:
	Field(sf::Vector2f position);
	bool stopUpdating();
	void setDuration(const ms &time);
	void update(const us &dt); 
	void fade(const us &dt);
	bool isFishInside();
	void initialize(Chance &random);
	bool onClick() override;
	~Field();
};

