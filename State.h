#pragma once
#include "Button.h"
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
	std::vector<Button> buttons;
	ClickableObject *currentlyClickedObj;

	virtual void createScenery() = 0;
	void addDrawable(sf::Drawable &object);
	void addButton(Button &clickableObject);
public:
	virtual void input(sf::Event &event);
	virtual void update(double dt) = 0;
	virtual void render();
	void setEngine(Engine *engine) { engineRef = engine; };
	State(Engine *engineRef);
	virtual ~State() { delete objects; };
};