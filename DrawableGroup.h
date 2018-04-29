#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <vector>

template <class T = sf::Drawable>
class DrawableGroup : public sf::Drawable
{
protected:
	std::vector<T*> children;
public:
	void add(T *newComponent);
	void remove(T *componentInstance);
	bool remove(int index);
	T& getComponent(int index);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	DrawableGroup() {};
	~DrawableGroup() {};
};