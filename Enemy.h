#pragma once
#include <string>
#include <iostream>
#include <random>
#include <ctime>

#include "Level.h"


class Enemy
{
private:
	std::default_random_engine engine = std::default_random_engine(time(0) - x + time(NULL) + y * 2 * time(0));
	std::uniform_int_distribution<int> random = std::uniform_int_distribution<int>(0, 100);
	int x;
	int y;
	int last;
	int exp = 0;
	int level = 1;
	double health = 2;
	double atk = 1;
	double def = 1;
	double hit = 100;

public:
	Enemy(int, int);
	~Enemy();
	bool enemyMove(Level &level);
	int getX();
	int getY();
	double getHealth();
	std::string getPosition();
	double attack();
	void defence(double);
	int getExp();
	void addExp(int exp);
	int getLevel();
	void levelUp();
};

