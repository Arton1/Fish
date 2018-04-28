#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"

class MainMenu : public State
{
	std::unique_ptr<Button> startButton;

	void changeOnInput(sf::Event &event);
	void render();
public:
	MainMenu();
	~MainMenu() {};
};

