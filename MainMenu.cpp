#include "MainMenu.h"
#include "Engine.h"
#include <SFML\Graphics.hpp>
#include <iostream>

MainMenu::MainMenu()
{
	startButton = std::make_unique<Button>();
}

void MainMenu::changeOnInput(sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed)
		std::cout << "PRESSED" << std::endl;
}

void MainMenu::render()
{
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(*startButton);
}
