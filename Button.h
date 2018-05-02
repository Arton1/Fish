#pragma once
#include "ClickableObject.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Button : public ClickableObject
{
	static sf::Font font;

	sf::Text label;
public:
	static bool setFont(std::string location);

	Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt);
	Button();
	~Button() {};
};