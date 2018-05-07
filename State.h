#pragma once
#include "DrawableGroup.h"
#include "ClickableGroup.h"
#include <chrono>
#include <memory>

class Engine;
class Clickable;
class Button;
typedef std::chrono::microseconds us;

namespace sf {
	class Event;
}

class State
{
protected:
	Engine *engineRef;
	
	std::unique_ptr<DrawableGrp> objects;
	ClickableGrp *clickables;
	ClickableGrp *buttons;
	Clickable *clickedRef;

	virtual void createScenery() = 0;
	void addDrawable(sf::Drawable *object);
	void addButton(Button *clickableObject);
public:
	virtual void input(sf::Event &event);
	virtual void update(us dt) = 0;
	virtual void render();
	void setEngine(Engine *engine) { engineRef = engine; };
	State(Engine *engineRef);
	virtual ~State() { };
};