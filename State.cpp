#include "State.h"
#include "Engine.h"

void State::render()
{
	sf::RenderWindow &window = engineRef->getWindow();
	window.draw(decorations);
	for (int i = 0; i < buttons.size(); i++)
		window.draw(buttons[i]);
}

State::State(Engine *engineRef)
{
	setEngine(engineRef);
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
	engineRef->setView(view);
}

void State::addDrawable(sf::Drawable *object)
{
	decorations.add(object);
}

void State::addButton(Button &clickableObject)
{
	buttons.push_back(clickableObject);
}

void State::input(sf::Event &event)
{
	switch (event.type) {
	case sf::Event::MouseButtonPressed: {
		sf::Vector2f worldCoordsOfMouse = engineRef->getWorldCoordsOfMouse();
		if (event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < buttons.size(); i++)
				if (buttons[i].gotClicked(worldCoordsOfMouse))
					currentlyClickedObj = &buttons[i];
		}
	}
	}
}