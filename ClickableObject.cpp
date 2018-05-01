#include "ClickableObject.h"
#include <iostream>

void ClickableObject::click(const sf::Vector2f &worldPos)
{
	if(onClick)
		if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
			onClick();
}

void ClickPtr::defaultClick()
{
	std::cout << "Clicked" << std::endl;
}
