#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"
#include <vector>
#include "DrawableGroup.h"

class MainMenu : public State
{

	void createScenery() override;

	bool onExit();
	bool onStart();
	bool onCredit();
public:
	void update(us dt) override;

	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

