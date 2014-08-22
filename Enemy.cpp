
#include "Enemy.h"


Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
}


Enemy::~Enemy()
{
}

bool Enemy::enemyMove(Level &level){
	//DICE ROLL LATER
	std::default_random_engine engine = std::default_random_engine(time(0)-x + y*time(0));
	std::uniform_int_distribution<int> random = std::uniform_int_distribution<int>(0, 3);
	int direction;

	direction = random(engine);
	int i = 0;
	while (last == direction && i < 5){
		direction = random(engine);
		i++;
	}
	switch (direction){
	case 0://North
		if (level.canMove(x,y-1)){
			level.setThing(x, y, '.');
			y--;
			level.setThing(x, y, 'E');
			last = 2;
		}
		last = -1;
		break;
	case 1://East
		if (level.canMove(x+1, y)){
			level.setThing(x, y, '.');
			x++;
			level.setThing(x, y, 'E');
			last = 3;
		}
		last = -1;
		break;
	case 2://South
		if (level.canMove(x, y + 1)){
			level.setThing(x, y, '.');
			y++;
			level.setThing(x, y, 'E');
			last = 0;
		}
		last = -1;
		break;
	case 3://West
		if (level.canMove(x-1, y)){
			level.setThing(x, y, '.');
			x--;
			level.setThing(x, y, 'E');
			last = 1;
		}
		last = -1;
		break;

	}

	// is there a player next to me??
	//		don't move
	// roll move dice
	// if 0, don't move, if 1 move
	// if 1, move in random directio
	return true;
}

int Enemy::getX(){
	return x;
}
int Enemy::getY(){
	return y;
}

double Enemy::getHealth(){
	return health;
}

std::string Enemy::getPosition(){


	char str[20];
	sprintf(str, "(%d, %d)", x, y);
	std::string s = str;
	return s;
}


double Enemy::attack(){

	int chance = random(engine);
	if (chance <= hit){
		return atk;
	}
	else{
		return 0;
	}
}

void Enemy::defence(double pAttack){

	int chance = random(engine);
	if (chance <= def*10){
		std::cout << "Enemy Dodged, took 0 damage" << std::endl;
		return;
	}
	else{
		std::cout << "Enemy took " << pAttack << " damage" << std::endl;
		health -= pAttack;
	}

}
int Enemy::getExp(){
	return exp;
}
void Enemy::addExp(int exp){
	this->exp += exp;
	if (this->exp >= ((level * 10) + 10)){
		levelUp();
		this->exp = 0;
	}
}
int Enemy::getLevel(){
	return level;
}
void Enemy::levelUp(){
	level++;
	std::cout << "ENEMY LEVELED UP" << std::endl;
	if (level % 2 == 0){
		def++;
	}
	else{
		atk++;
	}
	if (level % 5 == 0){
		hit += 5;
	}
}
