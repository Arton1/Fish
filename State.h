#pragma once
#include "ClickableObject.h"
#include "DrawableGroup.h"
#include <memory>

class Engine;

namespace sf {
	class Event;
}

class State
{
protected:
	Engine *engineRef;
	
	DrawableGroup *objects;
	std::vector<ClickableObject*> clickables;
	ClickableObject *currentlyClickedObj;

	virtual void createScenery() = 0;
	void addDrawable(sf::Drawable *object);
	void addClickable(ClickableObject *clickableObject);
public:
	virtual void input(sf::Event &event);
	virtual void update() = 0;
	virtual void render();
	void setEngine(Engine *engine) { engineRef = engine; };
	State(Engine *engineRef);
	virtual ~State() { delete objects; };
};