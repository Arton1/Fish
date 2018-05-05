#include "State.h"
#include "Engine.h"

void State::render()
{
	engineRef->getWindow().draw(*objects);
}

State::State(Engine *engineRef)
{
	setEngine(engineRef);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
	engineRef->setView(view);
	objects = new DrawableGroup<>();
}

void State::input(sf::Event &event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < clickables.size(); i++)
				if (clickables[i].gotClicked(worldCoordsOfMouse))
					currentlyClickedObj = &clickables[i];
		}
	}
	}
}