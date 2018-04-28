#pragma once

class Engine;

class State
{
	Engine *engineRef;
public:
	virtual void getInput() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual ~State() {};
};

