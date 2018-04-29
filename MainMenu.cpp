#include "MainMenu.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <iostream>

MainMenu::MainMenu(Engine *engineRef)
{
	setEngine(engineRef);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
	engineRef->setView(view);
	createScenery();
}

void MainMenu::createScenery() {
	sf::Vector2i buttonSize = sf::Vector2i(200, 100);
	sf::Vector2f buttonPosition = sf::Vector2f(-buttonSize.x / 2, 0);
	startButton = std::make_unique<Button>(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y/2 - 1.75 * buttonSize.y, sf::Color::Blue, "Start");
	creditButton = std::make_unique<Button>(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y/2, sf::Color::Red, "Credit");
	quitButton = std::make_unique<Button>(buttonSize.x, buttonSize.y, buttonPosition.x, -buttonSize.y/2 + 1.75 * buttonSize.y, sf::Color::Green, "Exit");
}

void MainMenu::changeOnInput(sf::Event &event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (startButton->clicked(worldCoordsOfMouse))
				std::cout << "Clicked button" << std::endl;
		}
		break;
	}
	}
}

void MainMenu::render()
{
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(*startButton);
	window.draw(*creditButton);
	window.draw(*quitButton);
}
