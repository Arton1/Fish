#pragma once
#include "State.h"
#include "Button.h"
#include <SFML/Graphics/Text.hpp>

class CreditMenu : public State
{
	sf::Text text;

	void createScenery() override;

	void onExitToMenu();
public:
	void update(double dt) override;

	CreditMenu(Engine *engineRef);
	~CreditMenu();
};