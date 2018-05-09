#include "CreditMenu.h"
#include "Button.h"
#include "Engine.h"
#include "MainMenu.h"
#include "Loader.h"

const char *CreditMenu::info[] = {
	"Created by:\n"
	"Artur Wyrozebski\n"
	"Student of Electronics and Information Technology Faculty\n"
	"at University of Technology in Warsaw, Poland\n"
	"Contact:\n"
	"arton-10@o2.pl or A.Wyrozebski@elka.pw.edu.pl\n"
	"\n"
	"Fish textures taken from: Terraria\n"
	"Not to be distributed"
};

CreditMenu::CreditMenu(Engine *engineRef):
	State(engineRef)
{
	createScenery();
}


void CreditMenu::createScenery()
{
	sf::Vector2f buttonSize = sf::Vector2f(200, 100);
	sf::Vector2f buttonPosition = sf::Vector2f(-buttonSize.x/2, -buttonSize.y / 2 + 1.75 * buttonSize.y);
	sf::Text *text = new sf::Text(*info, Loader::getInstance().getFont());
	text->setFillColor(sf::Color::Black);
	text->setPosition(-engineRef->getWindow().getView().getSize().x / 2+50, -engineRef->getWindow().getView().getSize().y / 2 + 25);
	addDrawable(text);
	
	std::function<bool()> callback;
	callback = std::bind(&CreditMenu::onExitToMenu, this);
	buttons.emplace_back(buttonSize.x, buttonSize.y, buttonPosition.x, buttonPosition.y, sf::Color::Green, "Exit", callback);
}

bool CreditMenu::onExitToMenu()
{
	engineRef->setState(new MainMenu(engineRef));
	return true;
}

void CreditMenu::update(us dt)
{
	if (currentlyClickedObj) {
		currentlyClickedObj->onClick();
		currentlyClickedObj = NULL;
	}
}

CreditMenu::~CreditMenu()
{
}
