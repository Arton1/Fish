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

	static std::function<bool(Fish*)> callback;

	sf::Color color;
	us timeElapsed;
	bool stopUpdate;
	double fadingSpeed;
	std::shared_ptr<Fish> fish;

	void reset();
public:
	Field(sf::Vector2f position);
	bool stopUpdating();
	inline void setFadingSpeed();
	void update(const us &dt); 
	void fade(const us &dt);
	bool isFishInside();
	void initialize(Chance &random);
	Fish& getFish();
	bool onClick() override;
	static void setCallback(std::function<bool(Fish*)> func);
	~Field();
};

