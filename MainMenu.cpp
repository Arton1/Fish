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
	startButton = std::make_unique<Button>();
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
}
