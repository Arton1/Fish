#pragma once

class Game
{
	int money;
public:
	static const int maxMoney;
public:
	bool addMoney(int value);
	bool substractMoney(int value);
	Game();
	~Game();
};

