#include "Game.h"

const int Game::maxMoney = 5000;

bool Game::addMoney(int value)
{
	if (money < maxMoney) {
		money += value;
		return true;
	}
	return false;
}

bool Game::substractMoney(int value)
{
	if (money - value < 0)
		return false;
	money -= value;
	return true;
}

Game::Game()
{
}


Game::~Game()
{
}
