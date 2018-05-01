#pragma once
#include "Object.h"

namespace ClickPtr {
	void defaultClick();
}

class ClickableObject : public Object
{
protected:
	void (*onClick)();
public:
	void click(const sf::Vector2f &worldMousePos);

	ClickableObject() {};
	virtual ~ClickableObject() {};
};
