#pragma once
#include "ClickableObject.h"
#include <chrono>

class Field : public ClickableObject
{
	sf::Color color;
	double timeElapsed;
	double duration;
	double fadingSpeed;

	void reset();
public:
	Field(sf::Vector2f position);

	bool update(const std::chrono::microseconds &dt); //returns true if have to stop updating
	void fade(const std::chrono::microseconds &dt);
	~Field();
};

