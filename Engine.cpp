#include "Engine.h"
#include "MainMenu.h"
#include "Button.h"

typedef std::chrono::high_resolution_clock Clock;

Engine::Engine() :
	pause(false)
{
	window.create(sf::VideoMode(800, 600), "Ryby");
	window.setVerticalSyncEnabled(true);
	setState(new MainMenu(this));
}

void Engine::run() {
	std::chrono::time_point<std::chrono::high_resolution_clock> lastTime = Clock::now();
	std::chrono::duration<double> frametime(0);
	while (window.isOpen()) {
		frametime = Clock::now() - lastTime;
		lastTime = Clock::now();
//		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(frametime).count() << std::endl;
		getInput();
		if(!pause)
			update(std::chrono::duration_cast<std::chrono::microseconds>(frametime));
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
			currState->input(event);
	}
}

void Engine::update(us dt) {
	currState->update(dt);
}

void Engine::render() {
	window.clear(sf::Color::White);
	currState->render();
	window.display();
}

void Engine::setState(State *newState) {
	if (newState) {
		currState.reset(newState);
	}
	else
		std::terminate();
}

void Engine::setView(const sf::View &view) { 
	window.setView(view);
}

sf::Vector2f Engine::getWorldCoordsOfMouse()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
	return worldPos;
}

Game& Engine::getGameInstance() const {
	return *gameInstance.get();
}

sf::RenderWindow& Engine::getWindow() { 
	return window;
}