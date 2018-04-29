#pragma once
#include "Object.h"

class ClickableObject : public Object
{
public:
	ClickableObject() {};
	~ClickableObject() {};

	virtual bool gotClicked(const sf::Vector2f &worldPos);
};
