#include "State.h"
#include "DrawableGroup.h"
#include "Engine.h"
#include "Button.h"

void State::render()
{
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(*objects);
}

State::State(Engine *engineRef)
{
	setEngine(engineRef);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
	engineRef->setView(view);
	objects = std::unique_ptr<DrawableGrp>();
	clickables = new ClickableGrp();
	buttons = new ClickableGrp();
	objects->add(clickables);
	buttons = clickables->add(new ClickableGrp());
}

void State::addDrawable(sf::Drawable *object)
{
	objects->add(object);
}

void State::addButton(Button *clickableObject)
{
	buttons->add(clickableObject);
}

void State::input(sf::Event &event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
				clickedRef = buttons->gotClicked(worldCoordsOfMouse);
		}
	}
	}
}