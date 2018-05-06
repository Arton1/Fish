#include "PlayState.h"
#include "Engine.h"
#include "MainMenu.h"
#include "Button.h"
#include "Loader.h"
#include <iostream>

static const sf::Vector2u areaSize = sf::Vector2u(12, 12);
static const unsigned fieldSize = Loader::getInstance().getTexture(Loader::Type::water).getSize().x;

using namespace std::chrono;

PlayState::PlayState(Engine *engine):
	State(engine),
	random(0, 100)
{
	createScenery();
}

PlayState::~PlayState()
{
}

void PlayState::createScenery()
{
	sf::Vector2f viewSize = engineRef->getWindow().getView().getSize();
	sf::Vector2f buttonSize;
	sf::Vector2f buttonPosition;
	std::function<bool()> callback;

	buttonSize = sf::Vector2f(150, 50);
	buttonPosition = sf::Vector2f(viewSize.x / 2 - buttonSize.x - 20, viewSize.y / 2 - buttonSize.y - 20);
	callback = std::bind(&PlayState::onExitToMenu, this);
	addButton(Button(buttonSize.x, buttonSize.y, buttonPosition.x, buttonPosition.y, sf::Color::Green, "Exit", callback));

	sf::Vector2f position;
	for (int i = 0; i < areaSize.x; i++) {
		area.emplace_back();
		for (int j = 0; j < areaSize.y; j++) {
			position.x = i*fieldSize - viewSize.x / 2 + 15;
			position.y = j*fieldSize - viewSize.y / 2 + 15;
			area[i].push_back(Field(position));
		}
	}
}

void PlayState::input(sf::Event & event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < buttons.size(); i++)
				if (buttons[i].gotClicked(worldCoordsOfMouse)) {
					currentlyClickedObj = &buttons[i];
					return;
				}
			for (int i = 0; i < area.size(); i++)
				for (int j = 0; j < area[i].size(); j++)
					if (area[i][j].gotClicked(worldCoordsOfMouse)) {
						currentlyClickedObj = &area[i][j];
						return;
					}
		}
	}
	}
}


void PlayState::update(us dt)
{
	if (currentlyClickedObj) {
		if(currentlyClickedObj->onClick())
			return; //have to return if the function causes to move to different state
		currentlyClickedObj = NULL;
	}
	createFish(dt);
	updateFields(dt);
}

void PlayState::render() {
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(*objects);
	for (int i = 0; i < buttons.size(); i++)
		window.draw(buttons[i]);
	for (int i = 0; i < area.size(); i++)
		for (int j = 0; j < area[i].size(); j++)
			window.draw(area[i][j]);
}

bool PlayState::onExitToMenu()
{
	engineRef->setState(new MainMenu(engineRef));
	return true;
}

void PlayState::createFish(us dt)
{
	if (elpsdTmFrLstTrigger.count() >= 1000) {
		i = random.getRandomValue(0, areaSize.x);
		j = random.getRandomValue(0, areaSize.y);
		fieldsUpdating.push_back(&area[i][j]);
		elpsdTmFrLstTrigger = elpsdTmFrLstTrigger.zero();
	}
	elpsdTmFrLstTrigger += duration_cast<std::chrono::milliseconds>(dt);
}

void PlayState::updateFields(us dt)
{
	std::list<Field*>::iterator it;
	int i = 0;
	for (it = fieldsUpdating.begin(); it != fieldsUpdating.end();) {
		if ((*it)->update(dt))
			it = fieldsUpdating.erase(it);
		else
			it++;
	}
}
