#pragma once
#include "State.h"
#include "Field.h"
#include "Chance.h"
#include <SFML\Graphics\Text.hpp>
#include <vector>
#include <list>

class Engine;

class PlayState : public State
{
	std::vector<std::vector<Field>> area;
	std::list<Field*> fieldsUpdating;

	sf::Text topRightText;
	std::list<sf::Text> clickedFishInfo;

	Chance random;
	std::chrono::milliseconds elpsdTmFrLstTrigger;
	std::chrono::microseconds nextFishTime;

	bool onExitToMenu();
	bool onFieldClicked(Fish *fishRef);
	void createScenery();
	void createFish(us dt);
	void updateFields(us dt);
	void setNextFishTime();

	void addClickedFishInfo(Fish &fishRef);
	void refreshClickedFishInfo();
public:
	void input(sf::Event &event) override;
	void update(us dt) override;
	void render() override;
	PlayState(Engine *engine);
	~PlayState() { };
};

