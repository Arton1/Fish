#pragma once
#include "ClickableObject.h"
#include <string>

class Button : public ClickableObject
{
public:
	enum State { NOTHING, CLICKED };
private:
	std::string label;
	State state;
public:
	Button(int sizeX, int sizeY, float posX, float posY, sf::Color color, std::string txt);
	Button();
	~Button() {};
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	int getState();
	void setState(State state);
};