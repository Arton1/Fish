#pragma once
#include "Global.h"
#include "Game.h"
#include "State.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

class Engine
{
	sf::RenderWindow window;
	std::unique_ptr<Game> gameInstance;
	std::unique_ptr<State> currState;

private:
	void getInput();
	void update();
	void render();

public:
	Engine();
	~Engine() {};

	void run();
	void setState(State *newState);
	void setView(const sf::View &view);

	Game& getGameInstance() const;
	sf::RenderWindow& getWindow();
};

