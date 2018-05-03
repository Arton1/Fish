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
	void input(sf::Event &event);
	void update();
	void render();

	void onExit();
	void onStart();
	void onCredit();
public:
	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

