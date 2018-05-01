#include "ClickableGroup.h"

void ClickableGroup::click(sf::Vector2f &mouseCoords)
{
	for(int i=0; i<children.size(); i++)
		children[i]->click(mouseCoords);
}
