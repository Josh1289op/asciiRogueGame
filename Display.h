#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Level.h"


class Display
{
private:
	Level level;
	Player player;
public:
	Display(Level &level, Player &player);
	~Display();
	void printLevel(Player &player);
};
