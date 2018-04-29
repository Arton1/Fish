#include "DrawableGroup.h"
#include <algorithm>

template<class T>
void DrawableGroup::add(T * newComponent)
{
	std::vector<Drawable*>::iterator itr = find(children.begin(), children.end(), newComponent);
	if (itr != children.end())
	{
		children.push_back(newComponent);
	}
}

template<class T>
void DrawableGroup::remove(T * componentInstance)
{
	std::vector<Drawable*>::iterator itr = find(children.begin(), children.end(), componentInstance);
	if (itr != children.end())
	{
		children.erase(itr);
	}
}

template<class T>
void DrawableGroup<T>::add(T * newComponent)
{
}

template<class T>
bool DrawableGroup::remove(int index)
{
	if (index > children.size())
		return false;
	std::vector<T*>::iterator itr;
	itr = children.begin();
	itr = itr + index;
	children.erase(itr);
	return true;
}

template<class T>
sf::Drawable& DrawableGroup::getComponent(int index)
{
	return *children[index];
}

template<class T>
void DrawableGroup::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}