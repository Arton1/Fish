#pragma once
#include "State.h"

class Engine;

class PlayState : public State
{
	void createScenery();

	void onExitToMenu();
public:
	void update();
	PlayState(Engine *engine);
	~PlayState();
};

