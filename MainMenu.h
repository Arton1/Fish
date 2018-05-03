#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"
#include <vector>
#include "ClickableGroup.h"
#include "DrawableGroup.h"

class MainMenu : public State
{

	void createScenery();
	void update();

	void onExit();
	void onStart();
	void onCredit();
public:
	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

