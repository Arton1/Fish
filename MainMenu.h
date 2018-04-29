#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"
#include <vector>
#include "ClickableGroup.h"
#include "DrawableGroup.h"

class MainMenu : public State
{
	DrawableGroup<> *objects;
	ClickableGroup *clickables;

	void createScenery();
	void changeOnInput(sf::Event &event);
	void render();
public:
	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

