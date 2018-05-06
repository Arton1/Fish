#pragma once
#include "Object.h"
#include <functional>

class ClickableObject : public Object
{
	bool defaultClick();
protected:
	std::function<bool(void)> callback;
public:
	virtual bool gotClicked(const sf::Vector2f &worldMousePos);
	virtual void setCallback(std::function<bool(void)> &func);
	virtual bool onClick();

	ClickableObject();
	virtual ~ClickableObject() {};
};
