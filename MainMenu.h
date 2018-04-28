#pragma once
#include "State.h"

class MainMenu : public State
{
	void getInput();
	void update();
	void render();
public:
	MainMenu();
	~MainMenu() {};
};

