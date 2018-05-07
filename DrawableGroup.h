#pragma once
#include "Group.h"
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <iostream>

template <class T>
class DrawableGroup : public Group<T>, public T
{
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	DrawableGroup() {};
	virtual ~DrawableGroup() { std::cout << "Deleted" << std::endl; };
};

template <class T>
void DrawableGroup<T>::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < children.size(); i++) {
		target.draw(*children[i].get());
	}
}

typedef DrawableGroup<sf::Drawable> DrawableGrp;