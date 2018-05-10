#include "Loader.h"
#include <iostream>

const int Loader::numberOfPNG = 4;
const char *Loader::path[numberOfPNG] = {
	"graphics/water.png",
	"graphics/common.png",
	"graphics/rare.png",
	"graphics/legendary.png"
};

Loader::Loader()
{
	if (!loadGraphics())
		terminate();
}

Loader::~Loader()
{
}

sf::Texture & Loader::getTexture(Type type)
{
	return *textures[type];
}

sf::Font & Loader::getFont()
{
	return font;
}

bool Loader::loadGraphics()
{
	bool passed = true;
	if (!font.loadFromFile("graphics/Crimson-Roman.ttf"))
		passed = false;
	for (int i = 0; i < numberOfPNG; i++) {
		sf::Texture *texture = new sf::Texture();
		if (!texture->loadFromFile(path[i]))
			passed = false;
		textures.emplace_back(texture);
	}
	return passed;
}

Loader& Loader::getInstance()
{
	static Loader loader;
	return loader;
}