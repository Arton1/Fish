#pragma once
#include <SFML\Graphics.hpp>

class Button : public sf::Drawable
{
	sf::RectangleShape body;
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	//Button(int sizeX, int sizeY, int posX, int posY);
	Button();
	~Button();
};