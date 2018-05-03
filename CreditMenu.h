#pragma once
#include "State.h"
#include "Button.h"

class CreditMenu : public State
{
	void createScenery() override;

	void onExitToMenu();
public:
	void update() override;

	CreditMenu(Engine *engineRef);
	~CreditMenu();
};