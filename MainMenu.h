#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"

class MainMenu : public State
{
	std::unique_ptr<Button> startButton;
	std::unique_ptr<Button> creditButton;
	std::unique_ptr<Button> quitButton;

	void createScenery();
	void changeOnInput(sf::Event &event);
	void render();
public:
	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

