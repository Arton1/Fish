#pragma once
#include <SFML\Graphics.hpp>

class Button : public sf::Drawable
{
public:
	enum State { NOTHING, CLICKED };
private:
	sf::RectangleShape body;
	State state;
public:
	Button(int sizeX, int sizeY, int posX, int posY, sf::Color color, sf::String txt);
	Button();
	~Button();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	bool clicked(sf::Vector2f worldPos);
	int getState();
	void setState(State state);
};