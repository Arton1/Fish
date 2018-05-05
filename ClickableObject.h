#pragma once
#include "Object.h"
#include <functional>

class ClickableObject : public Object
{
	void defaultClick();
protected:
	std::function<void(void)> callback;
public:
	virtual bool gotClicked(const sf::Vector2f &worldMousePos);
	virtual void setCallback(std::function<void(void)> &func);
	virtual void onClick();

	ClickableObject();
	virtual ~ClickableObject() {};
};
