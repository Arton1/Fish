#pragma once
#include "State.h"
#include "Field.h"
#include "Chance.h"
#include <vector>
#include <list>

class Engine;

class PlayState : public State
{
	std::vector<std::vector<Field>> area;
	std::list<Field*> fieldsUpdating;

	Chance random;
	std::chrono::milliseconds elpsdTmFrLstTrigger;
	std::chrono::microseconds nextFishTime;

	bool onExitToMenu();
	void createScenery();
	void createFish(us dt);
	void updateFields(us dt);
	void setNextFishTime();
public:
	void input(sf::Event &event) override;
	void update(us dt) override;
	void render() override;
	PlayState(Engine *engine);
	~PlayState() { };
};

