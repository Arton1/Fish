#include "ClickableObject.h"
#include <iostream>

ClickableObject::ClickableObject()
{
}

bool ClickableObject::gotClicked(const sf::Vector2f &worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
		return true;
}

ClickableObject::~ClickableObject() {}