#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
class Object : public sf::Drawable
{
protected:
	sf::Sprite body;
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	Object();
	virtual ~Object();
};

