#pragma once
#include "ClickableObject.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <iostream>

class Button : public ClickableObject
{
	static sf::Font font;

	sf::Text label;

	sf::Vector2f getLabelPositionToSetTo();
public:
	static bool setFont(std::string location);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt, std::function<void(void)> &callback);
	Button();
	~Button() {
		std::cout << "Deleted" << std::endl;
	};
};