#include "ClickableObject.h"
#include <iostream>

bool ClickableObject::isClicked()
{
	return gotClicked;
}

void ClickableObject::setClicked(bool clicked)
{
	gotClicked = clicked;
}

void ClickableObject::click(const sf::Vector2f &worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
		gotClicked = true;
}

ClickableObject::ClickableObject() :
	gotClicked(false)
{
}

void ClickPtr::defaultClick()
{
	std::cout << "Clicked" << std::endl;
}
