#include "Engine.h"
#include "MainMenu.h"

Engine::Engine()
{
	window.create(sf::VideoMode(800, 600), "Ryby");
	window.setVerticalSyncEnabled(true);
	setState(new MainMenu());
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
		else
			currState->changeOnInput(event);
	}
}

void Engine::update() {
	currState->update();
}

void Engine::render() {
	currState->render();
}

void Engine::setState(State *newState) {
	if (newState) {
		newState->setEngine(this);
		currState.reset(newState);
	}
	else
		terminate();
}

void Engine::setView(const sf::View &view) { 
	window.setView(view);
}
Game& Engine::getGameInstance() const {
	return *gameInstance.get();
}
sf::RenderWindow& Engine::getWindow() { 
	return window;
};