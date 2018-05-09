#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <vector>
#include <algorithm>
#include <memory>

class DrawableGroup : public sf::Drawable
{
protected:
	std::vector<std::unique_ptr<Drawable>> children;
public:
	int getSize();
	sf::Drawable& add(sf::Drawable *newComponent);
	void remove(sf::Drawable &componentInstance);
	bool remove(int index);
	sf::Drawable& getComponent(int index);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	DrawableGroup() {};
	~DrawableGroup();
};
