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
	virtual void input(sf::Event &event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void createScenery() = 0;
	virtual ~State() {};
	void setEngine(Engine *engine) { engineRef = engine; };
};