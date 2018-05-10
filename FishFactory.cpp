#include "FishFactory.h"
#include "Chance.h"
#include "Fish.h"
#include "CommonFish.h"
#include "RareFish.h"
#include "LegendaryFish.h"

static const int commonChance = 7000;
static const int rareChance = 2500;
static const int fullChance = 10000;
static const int legendaryChance = fullChance - commonChance - rareChance;

Fish * FishFactory::createFish(Chance & random)
{
	Fish *fishRef;
	int randomValue = random.getRandomValue(0, fullChance);
	if (randomValue < commonChance)
		fishRef = new CommonFish(random);
	else
		if (randomValue < commonChance + rareChance)
			fishRef = new RareFish(random);
		else
			fishRef = new LegendaryFish(random);
	return fishRef;
}