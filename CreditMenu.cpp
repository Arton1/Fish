#include "CreditMenu.h"
#include "Button.h"
#include "Engine.h"
#include "MainMenu.h"

CreditMenu::CreditMenu(Engine *engineRef):
	State(engineRef)
{
	createScenery();
}


void CreditMenu::createScenery()
{
	sf::Vector2f buttonSize = sf::Vector2f(200, 100);
	sf::Vector2f buttonPosition = sf::Vector2f(-buttonSize.x/2, -buttonSize.y / 2 + 1.75 * buttonSize.y);
//	clickables->add(new Button(buttonSize.x, buttonSize.y, buttonPosition.x, buttonPosition.y, sf::Color::Green, "Exit"));
}

void CreditMenu::onExitToMenu()
{
	engineRef->setState(new MainMenu(engineRef));
}

void CreditMenu::update()
{
//	if (clickables->getComponent(0).isClicked())
		onExitToMenu();
}

CreditMenu::~CreditMenu()
{
}
