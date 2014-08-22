#include "Position.h"


Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}


Position::~Position()
{
}

int Position::getX(){
	return x;
}

void Position::setX(){
	this->x = x;
}
void Position::setY(){
	this->y = y;
}

int Position::getY(){
	return y;
}


std::string Position::getPosition(){


	char str[20];
	sprintf(str, "(%d, %d)", x, y);
	std::string s = str;
	return s;
}