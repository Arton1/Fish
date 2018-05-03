#include "ClickableGroup.h"

void ClickableGroup::click(sf::Vector2f &mouseCoords)
{
	for(int i=0; i<children.size(); i++)
		children[i]->click(mouseCoords);
}

bool ClickableGroup::isClicked()
{
	for (int i = 0; i < children.size(); i++) {
		if (children[i]->isClicked())
			return true;
	}
}

void ClickableGroup::setClicked(bool clicked)
{
	for (int i = 0; i < children.size(); i++)
		children[i]->setClicked(clicked);
}


