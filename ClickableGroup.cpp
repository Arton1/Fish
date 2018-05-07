#include "ClickableGroup.h"

Clickable * ClickableGroup::gotClicked(const sf::Vector2f & worldMousePos)
{
	Clickable *object;
	std::vector<std::unique_ptr<Clickable>>::iterator itr;
	for (itr = children.begin(); itr != children.end(); itr++){
		object = itr->get()->gotClicked(worldMousePos);
		if (object)
			return object;
	}
}

void ClickableGroup::setCallback(std::function<bool(void)>& func)
{
	std::vector<std::unique_ptr<Clickable>>::iterator itr;
	for (itr = children.begin(); itr != children.end(); itr++)
		itr->get()->setCallback(func);
}

bool ClickableGroup::onClick()
{
	bool changesState = false;
	std::vector<std::unique_ptr<Clickable>>::iterator itr;
	for (itr = children.begin(); itr != children.end(); itr++)
		if (itr->get()->onClick())
			changesState = true;
	return changesState;
}
