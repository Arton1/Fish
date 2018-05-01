#pragma once
#include "ClickableObject.h"
#include "DrawableGroup.h"

class ClickableGroup : public DrawableGroup<ClickableObject>
{
public:
	void click(sf::Vector2f &mouseCoords);
	ClickableGroup() {};
	~ClickableGroup() {};
};

