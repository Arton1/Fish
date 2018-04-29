#pragma once
#include <SFML\Graphics.hpp>

class Button : public sf::Drawable
{
public:
	enum State { NOTHING, CLICKED };
private:
	sf::RectangleShape body;
	std::string label;
	State state;
public:
	Button(float sizeX, float sizeY, float posX, float posY, sf::Color color, std::string txt);
	Button();
	~Button();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool clicked(sf::Vector2f worldPos);
	int getState();
	void setState(State state);
};