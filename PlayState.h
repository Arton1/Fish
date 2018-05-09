#pragma once
#include "Game.h"
#include "State.h"
#include "Field.h"
#include "Chance.h"
#include <SFML\Graphics\Text.hpp>
#include <vector>
#include <list>

class Engine;

class PlayState : public State
{
	std::unique_ptr<Game> gameInstance;

	std::vector<std::vector<Field>> area;
	std::list<Field*> fieldsUpdating;

	sf::Text LastFishesText;
	std::list<sf::Text> clickedFishInfo;
	sf::Text moneyText;
	sf::Text moneyInfo;

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
	void refreshMoneyInfo();
public:
	void input(sf::Event &event) override;
	void update(us dt) override;
	void render() override;
	PlayState(Engine *engine, Game *gameRef);
	~PlayState();
};

