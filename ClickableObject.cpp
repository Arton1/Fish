#include "ClickableObject.h"

bool ClickableObject::gotClicked(const sf::Vector2f &worldPos)
{
	if (body.getGlobalBounds().contains(worldPos.x, worldPos.y))
		return true;
	return false;
}