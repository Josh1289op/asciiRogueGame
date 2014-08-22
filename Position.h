#pragma once
#include <string>
class Position
{
private:
	int x;
	int y;
public:
	Position(int , int);
	~Position();

	int getX();
	void setX();
	int getY();
	void setY();
	std::string getPosition();
};

