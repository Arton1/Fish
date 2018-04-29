#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics.hpp>

class ClickableObject : public sf::Drawable
{
protected:
	sf::Sprite body;
public:
	ClickableObject() {};
	virtual ~ClickableObject() {};

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

	virtual bool clicked(const sf::Vector2f &worldPos);
};
