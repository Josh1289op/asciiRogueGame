#pragma once
#include <vector>
#include <iostream>
#include <array>
#include <sstream>
#include <fstream>
#include "Position.h"

class Level
{
private:
	int num_rows = 0;
	int num_cols = 0;
	int x = 0;
	int y = 0;
	char **level; //pointer to a pointer of an char. 
	std::vector<Position> enemies;

public:
	Level();
	~Level();
	void readLevel();
	char ** Level::getLevel();
	int getCols();
	int getRows();
	int getX();
	int getY();
	
	void printLevel();
	void printPosition();
	void setPosition(int x, int y);
	bool canMove(int, int);
	void setThing(int x, int y, char a);
	char getThing(int x, int y);
	int getNumEnemies();
	Position getEnemy(int index);

};

