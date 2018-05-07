#include "ClickableObject.h"
#include <iostream>

ClickableObject::ClickableObject()
{
	callback = std::bind(&ClickableObject::defaultClick, this);
}

ClickableObject::~ClickableObject() {}

bool ClickableObject::defaultClick()
{
	std::cout << "Clicked" << std::endl;
	return false;
}

Clickable* ClickableObject::gotClicked(const sf::Vector2f &worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
		return this;
	else
		return NULL;
}

void ClickableObject::setCallback(std::function<bool(void)> &func)
{
	callback = func;
}

bool ClickableObject::onClick() {
	return callback();
}