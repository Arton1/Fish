#pragma once
#include "ClickableObject.h"
class Field : public ClickableObject
{
	sf::Color color;
	double timeElapsed;
	double duration;
	double fadingSpeed;
public:
	Field(sf::Vector2f position);

	void fade(double dt);
	~Field();
};

