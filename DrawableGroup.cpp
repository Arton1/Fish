#include "DrawableGroup.h"
#include <SFML/Graphics.hpp>

DrawableGroup::~DrawableGroup()
{
	for (int i = 0; i < children.size(); i++)
		delete children[i];
}

sf::Drawable* DrawableGroup::add(sf::Drawable *newComponent)
{
	children.push_back(newComponent);
	return newComponent;
}

void DrawableGroup::remove(sf::Drawable * componentInstance)
{
	std::vector<Drawable*>::iterator itr = find(children.begin(), children.end(), componentInstance);
	if (itr != children.end())
	{
		children.erase(itr);
	}
}

bool DrawableGroup::remove(int index)
{
	if (index > children.size())
		return false;
	std::vector<Drawable*>::iterator itr;
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
	for (int i = 0; i < children.size(); i++) 
		target.draw(*children[i]);
}


int DrawableGroup::getSize() {
	return children.size();
}


inline void DrawableGroup::pop_back()
{
	children.pop_back();
}
