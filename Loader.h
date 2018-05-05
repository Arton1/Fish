#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <vector>

class Loader
{
	sf::Font font;
	std::vector<sf::Texture> texture;
	bool loadGraphics();
public:
	static Loader& getInstance();
	Loader();
	Loader(Loader const&) = delete;
	Loader& operator=(Loader const&) = delete;
	~Loader();

	enum Type {
		water
	};

	sf::Texture& getTexture(Type type);
	sf::Font& getFont();
};

