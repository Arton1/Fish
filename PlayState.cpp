#include "PlayState.h"
#include "Engine.h"
#include "MainMenu.h"
#include "Button.h"
#include "Loader.h"

static const sf::Vector2u areaSize = sf::Vector2u(12, 12);
static const unsigned fieldSize = Loader::getInstance().getTexture(Loader::Type::water).getSize().x;

PlayState::PlayState(Engine *engine):
	State(engine)
{
	createScenery();
}

PlayState::~PlayState()
{
}

void PlayState::createScenery()
{
	sf::Vector2f viewSize = engineRef->getWindow().getView().getSize();
	sf::Vector2f buttonSize;
	sf::Vector2f buttonPosition;
	std::function<void()> callback;
	
	buttonSize = sf::Vector2f(150, 50);
	buttonPosition = sf::Vector2f(viewSize.x/2-buttonSize.x-20, viewSize.y/2-buttonSize.y-20);
	callback = std::bind(&PlayState::onExitToMenu, this);
	addClickable(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, buttonPosition.y, sf::Color::Green, "Exit", callback));

	sf::Vector2f position;
	for (int i = 0; i < areaSize.x; i++) {
		area.emplace_back();
		for (int j = 0; j < areaSize.y; j++) {
			position.x = i*fieldSize - viewSize.x/2 + 15;
			position.y = j*fieldSize - viewSize.y/2 + 15;
			area[i].emplace_back(Field(position));
		}
	}

}

void PlayState::onExitToMenu()
{
	engineRef->setState(new MainMenu(engineRef));
}

void PlayState::update()
{
	if (currentlyClickedObj) {
		currentlyClickedObj->onClick();
		currentlyClickedObj = NULL;
	}
}

void PlayState::render() {
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(*objects);
	for (int i = 0; i < area.size(); i++)
		for (int j = 0; j < area[i].size(); j++)
			window.draw(area[i][j]);
}