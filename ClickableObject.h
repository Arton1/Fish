#pragma once
#include "Object.h"
#include <functional>

class ClickableObject : public Object
{
public:
	virtual bool gotClicked(const sf::Vector2f &worldMousePos);
	virtual bool onClick() = 0;

	ClickableObject();
	virtual ~ClickableObject() = 0;
};
