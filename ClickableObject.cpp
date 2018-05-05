#include "ClickableObject.h"
#include <iostream>

ClickableObject::ClickableObject()
{
	callback = std::bind(&ClickableObject::defaultClick, this);
}

void ClickableObject::defaultClick()
{
	std::cout << "Clicked" << std::endl;
}

bool ClickableObject::gotClicked(const sf::Vector2f &worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
		return true;
}

void ClickableObject::setCallback(std::function<void(void)> &func)
{
	callback = func;
}

void ClickableObject::onClick() {
	callback();
}