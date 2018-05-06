#include "MainMenu.h"
#include "Engine.h"
#include "CreditMenu.h"
#include "PlayState.h"
#include <SFML\Graphics.hpp>

MainMenu::MainMenu(Engine *engineRef):
	State(engineRef)
{
	createScenery();
}

void MainMenu::createScenery() {
	sf::Vector2f buttonSize = sf::Vector2f(200, 100);
	sf::Vector2f buttonPosition = sf::Vector2f(-buttonSize.x / 2, 0);
	std::function<bool()> callback;

	callback = std::bind(&MainMenu::onStart, this);
	buttons.push_back(Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 - 1.75 * buttonSize.y, sf::Color::Blue, "Start", callback));
	callback = std::bind(&MainMenu::onCredit, this);
	buttons.push_back(Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2, sf::Color::Red, "Credit", callback));
	callback = std::bind(&MainMenu::onExit, this);
	buttons.push_back(Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 + 1.75 * buttonSize.y, sf::Color::Green, "Exit", callback));
}

void MainMenu::update(us dt) {
	if (currentlyClickedObj) {
		currentlyClickedObj->onClick();
		currentlyClickedObj = NULL;
	}
}

bool MainMenu::onExit() {
	engineRef->getWindow().close();
	return true;
}
bool MainMenu::onStart() {
	engineRef->setState(new PlayState(engineRef));
	return true;
}
bool MainMenu::onCredit() {
	engineRef->setState(new CreditMenu(engineRef));
	return true;
}