#pragma once
#include "ClickableObject.h"
#include "DrawableGroup.h"

class ClickableGroup : public DrawableGroup<ClickableObject>
{
public:
	void gotClicked(sf::Vector2f &mouseCoords);
	bool isClicked();
	void setClicked(bool clicked);
	ClickableGroup() {};
	~ClickableGroup() {};
};

