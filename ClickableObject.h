#pragma once
#include "Object.h"
#include "Clickable.h"
#include <functional>

class ClickableObject : public Object<Clickable>
{
	bool defaultClick();
	std::function<bool(void)> callback;
public:
	virtual Clickable* gotClicked(const sf::Vector2f &worldMousePos);
	virtual void setCallback(std::function<bool(void)> &func);
	virtual bool onClick();

	ClickableObject();
	virtual ~ClickableObject() = 0;
};
