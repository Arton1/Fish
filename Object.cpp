#include "Object.h"
#include <iostream>

void Object::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
}

Object::Object()
{
}


Object::~Object()
{
}
