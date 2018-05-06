#pragma once
#include "ClickableObject.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <iostream>

class Button : public ClickableObject
{
	sf::Text label;

	sf::Vector2f labelPositionToSetTo();
public:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt, std::function<bool(void)> &callback);
	Button();
	~Button() {};
};