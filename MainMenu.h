#pragma once
#include "Global.h"
#include "State.h"
#include "Button.h"
#include <vector>

class MainMenu : public State
{
	std::vector<ClickableObject> clickables;
	std::vector<sf::Drawable> drawables;

	void createScenery();
	void changeOnInput(sf::Event &event);
	void render();
public:
	MainMenu(Engine *engineRef);
	~MainMenu() {};
};

