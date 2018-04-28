#pragma once

class Engine;

namespace sf {
	class Event;
}

class State
{
protected:
	Engine *engineRef;

public:
	virtual void changeOnInput(sf::Event &event) = 0;
	virtual void update() {};
	virtual void render() = 0;
	virtual ~State() {};
	void setEngine(Engine *engine) { engineRef = engine; };
};