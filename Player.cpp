#include "Player.h"


Player::Player(int x, int y, std::string name)
{
	this->x = x;
	this->y = y;
	this->name = name;
}
Player::Player()
{

}


Player::~Player()
{
}


void Player::moveW(Level &level){
	if (level.canMove(x, y - 1)){
		level.setThing(x, y, '.');
		y--;
		level.setThing(x, y, '@');
	}
}

void Player::moveD(Level &level){
	if (level.canMove(x + 1, y)){
		level.setThing(x, y, '.');
		x++;
		level.setThing(x, y, '@');
	}
}

void Player::moveS(Level &level){
	if (level.canMove(x, y + 1)){
		level.setThing(x, y, '.');
		y++;
		level.setThing(x, y, '@');
	}
}

void Player::moveA(Level &level){
	if (level.canMove(x - 1, y)){
		level.setThing(x, y, '.');
		x--;
		level.setThing(x, y, '@');
	}
}

void Player::printPosition(){
	std::cout << "(" << x << "," << y << ")" ;

}
std::string Player::getName(){
	return name;
}
double Player::getHealth(){
	return health;
}

int Player::getX(){
	return x;
}
int Player::getY(){
	return y;
}

double Player::attack(){
	std::cout << random(engine);
	std::cout << random(engine);
	int chance = random(engine);
	if (chance <= hit){
		return atk;
	}
	else{
		return 0;
	}
}
void Player::defence(double eAttack){
	int chance = random(engine);
	if (chance <= def * 10){
		std::cout << "Player Dodged, took 0 damage" << std::endl;
		return;
	}
	else{
		std::cout << "Player took " << eAttack << " damage" << std::endl;
		health -= eAttack;
	}

}
int Player::getExp(){
	return exp;
}
void Player::addExp(int exp){
	this->exp += exp;
	if (this->exp >= ((level*50)+10)){
		levelUp();
		this->exp = 0;
	}
}
int Player::getLevel(){
	return level;
}
void Player::levelUp(){
	level++;
	std::cout << "Player Leveled Up! Level: " << level << std::endl;
	if (level % 2 == 0){
		atk++;
	}
	else{
		def++;
	}
	if (level % 5 == 0){
		hit += 5;
	}
}