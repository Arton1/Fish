#pragma once
#include "State.h"
#include "Button.h"
#include <SFML/Graphics/Text.hpp>

class CreditMenu : public State
{
	void createScenery() override;

	bool onExitToMenu();
public:
	void update(us dt) override;

	CreditMenu(Engine *engineRef);
	~CreditMenu();
};