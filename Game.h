#pragma once

class Game
{
	int money;
public:
	static const int maxMoney;
public:
	int getMoney();
	bool addMoney(int value);
	bool substractMoney(int value);
	Game();
	~Game();
};

