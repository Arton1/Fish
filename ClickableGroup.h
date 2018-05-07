#pragma once
#include "Clickable.h"
#include "DrawableGroup.h"

class ClickableGroup : public DrawableGroup<Clickable> //Group, Drawable, Clickable
{
public:
	virtual Clickable* gotClicked(const sf::Vector2f &worldMousePos);
	virtual void setCallback(std::function<bool(void)> &func);
	virtual bool onClick();
	ClickableGroup() {};
	~ClickableGroup() {};
};

typedef ClickableGroup ClickableGrp;