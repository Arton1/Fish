#include "Engine.h"
#include "MainMenu.h"

Engine::Engine()
{
	window.create(sf::VideoMode(800, 600), "Ryby");
	setState();
}

void Engine::run() {
	while (window.isOpen()) {
		getInput();
		update();
		render();
	}
}

void Engine::getInput() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	currState->getInput();
}

void Engine::update() {
	currState->update();
}

void Engine::render() {
	currState->render();
}

void Engine::setState() 
{
	currState.reset(new MainMenu());
}
