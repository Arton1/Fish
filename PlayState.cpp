#include "PlayState.h"
#include "Engine.h"
#include "MainMenu.h"
#include "Button.h"
#include "Loader.h"
#include <iostream>
#include <functional>
#include "Fish.h"
#include <sstream>

static const sf::Vector2u areaSize = sf::Vector2u(12, 12);
static const unsigned fieldSize = Loader::getInstance().getTexture(Loader::Type::water).getSize().x;
static const sf::Vector2f clickedFishInfoPosition = sf::Vector2f(Engine::windowSizeX/5 + 35, -Engine::windowSizeY/2 + 265);
static const sf::Vector2f moneyInfoPosition = sf::Vector2f(Engine::windowSizeX / 5 + 35, -Engine::windowSizeY / 2 + 25);

using namespace std::chrono;

PlayState::PlayState(Engine *engine, Game *gameRef) :
	State(engine),
	random(0, 100)
{
		if (gameRef)
			gameInstance = std::unique_ptr<Game>(gameRef);
		else
			gameInstance = std::unique_ptr<Game>(new Game());
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
	std::function<bool()> callback;
	
	sf::Text *lastFishesText = new sf::Text("Last 3 fishes info:", Loader::getInstance().getFont(), 25);
	lastFishesText->setPosition(clickedFishInfoPosition.x, clickedFishInfoPosition.y);
	lastFishesText->setFillColor(sf::Color::Black);
	addDrawable(lastFishesText);
	sf::Text *moneyText = new sf::Text("Current money:", Loader::getInstance().getFont(), 25);
	moneyText->setPosition(moneyInfoPosition);
	moneyText->setFillColor(sf::Color::Black);
	addDrawable(moneyText);
	moneyInfo.setFont(Loader::getInstance().getFont());
	moneyInfo.setPosition(moneyInfoPosition.x, moneyInfoPosition.y + 30);
	moneyInfo.setCharacterSize(25);
	moneyInfo.setFillColor(sf::Color::Black);
	refreshMoneyInfo();

	buttonSize = sf::Vector2f(150, 50);
	buttonPosition = sf::Vector2f(viewSize.x / 2 - buttonSize.x - 20, viewSize.y / 2 - buttonSize.y - 20);
	callback = std::bind(&PlayState::onExitToMenu, this);
	buttons.emplace_back(buttonSize.x, buttonSize.y, buttonPosition.x, buttonPosition.y, sf::Color::Green, "Exit", callback);

	std::function<bool(Fish*)> callb;
	callb = std::bind(&PlayState::onFieldClicked, this, std::placeholders::_1);
	Field::setCallback(callb);
	sf::Vector2f position;
	for (int i = 0; i < areaSize.x; i++) {
		area.emplace_back();
		for (int j = 0; j < areaSize.y; j++) {
			position.x = i*fieldSize - viewSize.x / 2 + 15;
			position.y = j*fieldSize - viewSize.y / 2 + 15;
			area[i].push_back(Field(position));
		}
	}
}

void PlayState::input(sf::Event & event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < buttons.size(); i++)
				if (buttons[i].gotClicked(worldCoordsOfMouse)) {
					currentlyClickedObj = &buttons[i];
					return;
				}
			for (int i = 0; i < area.size(); i++)
				for (int j = 0; j < area[i].size(); j++)
					if (area[i][j].gotClicked(worldCoordsOfMouse)) {
						currentlyClickedObj = &area[i][j];
						return;
					}
		}
	}
	}
}


void PlayState::update(us dt)
{
	if (currentlyClickedObj) {
		if(currentlyClickedObj->onClick())
			return; //have to return if the function causes to move to different state
		currentlyClickedObj = NULL;
	}
	createFish(dt);
	updateFields(dt);
}

void PlayState::render() {
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(decorations);
	for (auto itr = buttons.begin(); itr != buttons.end(); itr++)
		window.draw(*itr);
	for (auto itr = area.begin(); itr != area.end(); itr++)
		for (auto iter = itr->begin(); iter != itr->end(); iter++)
			window.draw(*iter);
	if(clickedFishInfo.size())
		window.draw(clickedFishInfo.front());
	for (auto itr = clickedFishInfo.begin(); itr != clickedFishInfo.end(); itr++)
		window.draw(*itr);
	window.draw(moneyInfo);
}

bool PlayState::onExitToMenu()
{
	engineRef->setState(new MainMenu(engineRef));
	return true;
}

bool PlayState::onFieldClicked(Fish *fishRef)
{
	if (fishRef) {
		addClickedFishInfo(*fishRef);
		gameInstance->addMoney(fishRef->getCost());
		refreshMoneyInfo();
	}
	return false;
}

void PlayState::createFish(us dt)
{
	if (elpsdTmFrLstTrigger >= nextFishTime) {
		Field *field;
		do {
			int i = random.getRandomValue(0, areaSize.x - 1);
			int j = random.getRandomValue(0, areaSize.y - 1);
			field = &area[i][j];
		} while (field->isFishInside());
		field->initialize(random);
		fieldsUpdating.push_back(field);
		elpsdTmFrLstTrigger = elpsdTmFrLstTrigger.zero();
		setNextFishTime();
	}
	elpsdTmFrLstTrigger += duration_cast<milliseconds>(dt);
}

void PlayState::setNextFishTime()
{
	int number = random.getRandomValue(0, 100);
	if (number < 67)
		number = random.getRandomValue(300, 500);
	else
		number = random.getRandomValue(900, 400);
	nextFishTime = milliseconds(number);
}

void PlayState::addClickedFishInfo(Fish & fishRef)
{
	std::string text;
	sf::Font &font = Loader::getInstance().getFont();
	std::stringstream stream;
	stream << fishRef.getTypeString() << " " << fishRef.getCost();
	text = stream.str();
	clickedFishInfo.emplace_front(text, font, 25);
	clickedFishInfo.front().setFillColor(sf::Color::Black);
	refreshClickedFishInfo();
}

void PlayState::refreshClickedFishInfo()
{
	if (clickedFishInfo.size() > 3)
		clickedFishInfo.pop_back();
	std::list<sf::Text>::iterator itr;
	int i;
	for (itr = clickedFishInfo.begin(), i = 1; itr != clickedFishInfo.end(); itr++, i++) {
		itr->setPosition(clickedFishInfoPosition.x, clickedFishInfoPosition.y + 25 * i);
	}
}

void PlayState::refreshMoneyInfo()
{
	std::string text;
	std::stringstream stream;
	stream << gameInstance->getMoney();
	stream >> text;
	moneyInfo.setString(text);
	moneyInfo.setPosition(moneyInfoPosition.x, moneyInfoPosition.y + 30);
}

void PlayState::updateFields(us dt)
{
	std::list<Field*>::iterator it;
	int i = 0;
	for (it = fieldsUpdating.begin(); it != fieldsUpdating.end();) {
		if ((*it)->stopUpdating())
			it = fieldsUpdating.erase(it);
		else {
			(*it)->update(dt);
			it++;
		}
	}
}