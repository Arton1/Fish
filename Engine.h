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

	static sf::Font font;
private:
	void loadFromFiles();

	void getInput();
	void update();
	void render();
public:
	Engine();
	~Engine() {};

	void run();
	void setState(State *newState);
	void setView(const sf::View &view);
	static sf::Font& getFont();
	static bool setFont(std::string location);

	sf::Vector2f getWorldCoordsOfMouse();

	Game& getGameInstance() const;
	sf::RenderWindow& getWindow();
};

