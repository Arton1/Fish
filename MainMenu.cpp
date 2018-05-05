#include "MainMenu.h"
#include "Engine.h"
#include "CreditMenu.h"
#include <SFML\Graphics.hpp>
#include <iostream>

MainMenu::MainMenu(Engine *engineRef):
	State(engineRef)
{
	createScenery();
}

void MainMenu::createScenery() {
	sf::Vector2f buttonSize = sf::Vector2f(200, 100);
	sf::Vector2f buttonPosition = sf::Vector2f(-buttonSize.x / 2, 0);
	std::function<void()> callback;

	callback = std::bind(&MainMenu::onStart, this);
	addClickable(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 - 1.75 * buttonSize.y, sf::Color::Blue, "Start", callback));
	callback = std::bind(&MainMenu::onCredit, this);
	addClickable(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2, sf::Color::Red, "Credit", callback));
	callback = std::bind(&MainMenu::onExit, this);
	addClickable(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 + 1.75 * buttonSize.y, sf::Color::Green, "Exit", callback));
}

void MainMenu::update() {
	if (currentlyClickedObj) {
		currentlyClickedObj->onClick();
		currentlyClickedObj = NULL;
	}
}

void MainMenu::onExit() {
	engineRef->getWindow().close();
}
void MainMenu::onStart() {

}
void MainMenu::onCredit() {
	engineRef->setState(new CreditMenu(engineRef));
}