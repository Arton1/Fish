#include "DrawableGroup.h"
#include <SFML/Graphics.hpp>
#include <iostream>

DrawableGroup::~DrawableGroup()
{
}

sf::Drawable& DrawableGroup::add(sf::Drawable *newComponent)
{
	children.emplace_back(newComponent);
	return *newComponent;
}

void DrawableGroup::remove(sf::Drawable  &componentInstance)
{
	std::vector<std::unique_ptr<Drawable>>::iterator itr;
	if (itr != children.end())
	{
		if(itr->get() == &componentInstance)
			children.erase(itr);
	}
}

bool DrawableGroup::remove(int index)
{
	if (index > children.size())
		return false;
	std::vector<std::unique_ptr<Drawable>>::iterator itr;
	itr = children.begin();
	itr = itr + index;
	children.erase(itr);
	return true;
}

sf::Drawable& DrawableGroup::getComponent(int index)
{
	return *children[index];
}

void DrawableGroup::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto itr = children.begin(); itr != children.end(); itr++) 
		target.draw(*itr->get());
}


int DrawableGroup::getSize() {
	return children.size();
}
