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
	clickables.emplace_back(Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 - 1.75 * buttonSize.y, sf::Color::Blue, "Start"));
	objects->add(&clickables[clickables.size() - 1]);
	std::function<void()> f = std::bind(&MainMenu::onExit, this);
	clickables[0].setCallback(f);
//	clickables.emplace_back(Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2, sf::Color::Red, "Credit"));
//	clickables.emplace_back(Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 + 1.75 * buttonSize.y, sf::Color::Green, "Exit"));
}

void MainMenu::update() {
	if (currentlyClickedObj) {
		currentlyClickedObj->onClick();
		currentlyClickedObj = NULL;
	}
	std::cout << currentlyClickedObj << std::endl;
}

void MainMenu::onExit() {
	engineRef->getWindow().close();
}
void MainMenu::onStart() {

}
void MainMenu::onCredit() {
	engineRef->setState(new CreditMenu(engineRef));
}