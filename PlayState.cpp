#include "PlayState.h"
#include "Engine.h"
#include "MainMenu.h"
#include "Button.h"

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
