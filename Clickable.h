#pragma once
#include <functional>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Clickable : public sf::Drawable {
public:
	virtual Clickable* gotClicked(const sf::Vector2f &worldMousePos) = 0; //returns pointer to clicked object if it got clicked, otherwise NULL.
	virtual bool onClick() = 0; //have to return true if the function causes to change state.
	virtual void setCallback(std::function<bool(void)> &func) = 0;
};