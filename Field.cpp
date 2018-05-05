#include "Field.h"
#include <SFML\Graphics.hpp>
#include "Loader.h"
#include <iostream>

Field::Field(sf::Vector2f position)
{
	sf::Texture &texture = Loader::getInstance().getTexture(Loader::Type::water);
	body.setTexture(texture);
	body.setPosition(position);
}


Field::~Field()
{

}
