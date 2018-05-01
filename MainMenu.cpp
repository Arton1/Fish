#include "MainMenu.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <iostream>

MainMenu::MainMenu(Engine *engineRef)
{
	setEngine(engineRef);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
	engineRef->setView(view);
	objects = new DrawableGroup<>();
	clickables = new ClickableGroup();
	objects->add(clickables);
	createScenery();
}

void MainMenu::createScenery() {
	sf::Vector2f buttonSize = sf::Vector2f(200, 100);
	sf::Vector2f buttonPosition = sf::Vector2f(-buttonSize.x / 2, 0);
	clickables->add(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 - 1.75 * buttonSize.y, sf::Color::Blue, "Start"));
	clickables->add(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2, sf::Color::Red, "Credit"));
	clickables->add(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y / 2 + 1.75 * buttonSize.y, sf::Color::Green, "Exit"));
}

void MainMenu::changeOnInput(sf::Event &event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
			clickables->click(worldCoordsOfMouse);
			}
		}
		
	}
}

void MainMenu::render()
{
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(*objects);
}
