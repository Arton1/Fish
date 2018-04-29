#pragma once
#include "ClickableObject.h"
#include "DrawableGroup.h"

class ClickableGroup : public DrawableGroup<ClickableObject>
{
public:
	ClickableGroup() {};
	~ClickableGroup() {};
};

