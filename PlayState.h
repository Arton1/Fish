#pragma once
#include "State.h"
#include "Field.h"
#include <vector>

class Engine;

class PlayState : public State
{
	std::vector<std::vector<Field>> area;

	void onExitToMenu();

	void createScenery();
public:
	void input(sf::Event &event) override;
	void update() override;
	void render() override;
	PlayState(Engine *engine);
	~PlayState();
};

