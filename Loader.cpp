#include "Loader.h"
#include <iostream>

Loader::Loader()
{
	texture.emplace_back();
	if (!loadGraphics())
		terminate();
}

Loader::~Loader()
{
}

sf::Texture & Loader::getTexture(Type type)
{
	return texture[type];
}

sf::Font & Loader::getFont()
{
	return font;
}

bool Loader::loadGraphics()
{
	if (font.loadFromFile("Crimson-Roman.ttf") &&
		texture[0].loadFromFile("water.png"));
		return true;
	return false;
}

Loader& Loader::getInstance()
{
	static Loader loader;
	return loader;
}