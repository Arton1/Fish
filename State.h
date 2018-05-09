#pragma once
#include "Button.h"
#include "DrawableGroup.h"
#include <chrono>
#include <vector>

class Engine;
typedef std::chrono::microseconds us;

namespace sf {
	class Event;
}

class State
{
protected:
	Engine *engineRef;
	
	DrawableGroup decorations;
	std::vector<Button> buttons;
	ClickableObject *currentlyClickedObj;

	virtual void createScenery() = 0;
	void addDrawable(sf::Drawable *object);
	void addButton(Button &clickableObject);
public:
	virtual void input(sf::Event &event);
	virtual void update(us dt) = 0;
	virtual void render();
	void setEngine(Engine *engine) { engineRef = engine; };
	State(Engine *engineRef);
	virtual ~State() {};
};