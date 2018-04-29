#pragma once
#include "ClickableObject.h"
#include "DrawableGroup.h"

class ClickableGroup : virtual public DrawableGroup<ClickableObject>, virtual public ClickableObject
{
public:

	ClickableGroup() {};
	~ClickableGroup() {};
};

