#include "ClickableObject.h"
#include <iostream>

ClickableObject::ClickableObject()
{
	callback = std::bind(&ClickableObject::defaultClick, this);
}

bool ClickableObject::defaultClick()
{
	std::cout << "Clicked" << std::endl;
	return false;
}

bool ClickableObject::gotClicked(const sf::Vector2f &worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
		return true;
}

void ClickableObject::setCallback(std::function<bool(void)> &func)
{
	callback = func;
}

bool ClickableObject::onClick() {
	return callback();
}