#pragma once
#include "Object.h"

namespace ClickPtr {
	void defaultClick();
}

class ClickableObject : public Object
{
protected:
	bool gotClicked;
public:
	virtual bool isClicked();
	virtual void setClicked(bool clicked);

	virtual void click(const sf::Vector2f &worldMousePos);

	ClickableObject();
	virtual ~ClickableObject() {};
};
