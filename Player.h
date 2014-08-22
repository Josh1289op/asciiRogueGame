#pragma once
#include <string>
#include <vector>
#include "Level.h"
#include "Enemy.h"

class Player
{
private:
	std::default_random_engine engine = std::default_random_engine(time(0) - x + y * 2 * time(0) * time(0));
	std::uniform_int_distribution<int> random = std::uniform_int_distribution<int>(0, 100);

	int x;
	int y;
	int last;
	std::string name;
	int level = 1;
	int exp = 0;
	double health = 100;
	double atk = 1;
	double def = 2;
	double hit = 50;

public:
	Player(int, int, std::string);
	Player();
	~Player();

	void moveW(Level &level);
	void moveD(Level &level);
	void moveS(Level &level);
	void moveA(Level &level);
	void printPosition();
	std::string getName();
	double getHealth();
	int getY();
	int getX();
	double attack();
	void defence(double);
	int getExp();
	void addExp(int exp);
	int getLevel();
	void levelUp();

};

