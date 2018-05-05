#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"
#include <vector>
#include "DrawableGroup.h"

class MainMenu : public State
{

	void createScenery() override;

	void onExit();
	void onStart();
	void onCredit();
public:
	void update() override;

	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

