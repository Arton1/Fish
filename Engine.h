#pragma once
#include "Global.h"
#include "Game.h"
#include "State.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <chrono>

class Engine
{
	sf::RenderWindow window;
	std::unique_ptr<Game> gameInstance;
	std::unique_ptr<State> currState;

	void getInput();
	void update(std::chrono::microseconds dt);
	void render();
public:
	Engine();
	~Engine() {};

	void run();
	void setState(State *newState);
	void setView(const sf::View &view);

	sf::Vector2f getWorldCoordsOfMouse();

	Game& getGameInstance() const;
	sf::RenderWindow& getWindow();
};

