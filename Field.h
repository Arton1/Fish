#pragma once
#include "ClickableObject.h"
#include <chrono>
#include "Fish.h"
#include "FishFactory.h"
#include <memory>

class Chance;

class Field : public ClickableObject
{

	static std::function<bool(Fish*)> callback;

	bool stopUpdate;
	std::shared_ptr<Fish> fish;

	void reset();
public:
	Field(sf::Vector2f position);
	bool stopUpdating();
	void update(const us &dt);
	bool isFishInside();
	void initialize(Chance &random);
	Fish& getFish();
	bool onClick() override;
	static void setCallback(std::function<bool(Fish*)> func);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	~Field();
};

