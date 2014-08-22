#include "Level.h"


Level::Level()
{

}


Level::~Level()
{
	for (int y = 0; y < num_rows; y++)
	{
		delete[] level[y];
	}

	delete[] level;
}


void Level::readLevel(){

	std::ifstream read;
	read.open("level1.txt");
	read >> num_rows >> num_cols;

	level = new char*[num_rows - 1];

	//this code initialized each rows columns to the num of columns
	for (int y = 0; y < num_rows; y++){
		level[y] = new char[num_cols - 1];
	}
	//reads in each line and assigns it to a position in the array. 
	std::string line;
	getline(read, line);
	for (int row = 0; row < num_rows; row++){
		getline(read, line);
		for (int col = 0; col < num_cols; col++){
			if (col < int(line.length())){
				if (line[col] == '@'){
					this->y = row;
					this->x = col;
				}
				else if (line[col] == 'E'){
					enemies.push_back(Position(col, row));
				}
				level[row][col] = line[col];
			}
		}
	}
}

char** Level::getLevel(){
	return level;

}

int Level::getCols(){ 
	return num_cols; 
}
int Level::getRows(){ 
	return num_rows; 
}
int Level::getX(){
	return x;
}
int Level::getY(){
	return y;
}



void Level::printPosition(){
	std::cout << "(" << x << "," << y << ")" << std::endl;

}

void Level::setPosition(int x, int y){
	this->x = x;
	this->y = y;
}


bool Level::canMove(int x, int y){
	if (level[y][x] == '.'){
		return true;
	}
	else{
		return false;
	}
}

void Level::setThing(int x, int y, char a){
	level[y][x] = a;
	if (a == '@'){
		this->y = y;
		this->x = x;
	}
}

char Level::getThing(int x, int y){
	return level[y][x];
}

int Level::getNumEnemies(){
	return enemies.size();
}

Position Level::getEnemy(int index){
	return enemies[index];
}
