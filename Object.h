#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
template <class T>
class Object : public T
{
protected:
	sf::Sprite body;
public:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	Object() {};
	virtual ~Object() {};
};

template <class T>
void Object<T>::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
}

typedef Object<sf::Drawable> Drawable;