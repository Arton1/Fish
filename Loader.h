#pragma once
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Font.hpp>
#include <vector>
#include <memory>

class Loader
{
public:
	enum Type {
		water,
		common,
		rare,
		legendary
	};
private:
	static const char *path[];
	static const int numberOfPNG;

	sf::Font font;
	std::vector<std::unique_ptr<sf::Texture>> textures;
	bool loadGraphics();
public:
	static Loader& getInstance();
	Loader();
	Loader(Loader const&) = delete;
	Loader& operator=(Loader const&) = delete;
	~Loader();

	sf::Texture& getTexture(Type type);
	sf::Font& getFont();
};

