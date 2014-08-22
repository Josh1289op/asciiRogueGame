#include <iostream>
#include <conio.h>
#include <string>

#include "Level.h"
#include "Enemy.h"
#include "Player.h"
#include "Display.h"
using namespace std;

void moveEnemies(Level &level, vector<Enemy> &enemies);
void gotoxy(int column, int line);
bool playerAttack(Level &level, Player &player, vector<Enemy> &enemies);
void enemyAttack(Level &level, vector<Enemy> &enemies);



int main(){
	char input;
	Level level = Level();
	cout << "Getting Level" << endl;
	level.readLevel();
	cout << "Level Got" << endl << "Enter a Name:";
	std::string name;
	cin >> name;
	Player player = Player(level.getX(), level.getY(), name);
	Position enemy = Position(0, 0);
	vector<Enemy> enemies;
	for (int i = 0; i < level.getNumEnemies(); i++){
		enemy = level.getEnemy(i);
		enemies.push_back(Enemy(enemy.getX(), enemy.getY()));
		cout << "Enemy " << i + 1 << " Position: " << enemy.getPosition() << endl;

	}
	Display display = Display(level, player);

	bool game = true;


	while(true){
		
		moveEnemies(level, enemies);
		display.printLevel(player);
		cout << "Number of Kills: " << level.getNumEnemies() - enemies.size() << endl;
		input = '0';
		enemyAttack(level, enemies);
		if (playerAttack(level, player, enemies) == false){
			game = false;
		}
		while (!(input == 'a' || input == 'A' || input == 's' || input == 's' || input == 'w' || input == 'W' || input == 'd' || input == 'D')){
			input = _getch();
		}
		

		switch (input){
		case 'w':
		case 'W':
			player.moveW(level); 
			break;
		case 'd':
		case 'D':
			player.moveD(level);
			break;
		case 's':
		case 'S':
			player.moveS(level);
			break;
		case 'a':
		case 'A':
			player.moveA(level);
			break;
		}

		cout << string(15, '\n');

	}


	return 0;
}


void moveEnemies(Level &level, vector<Enemy> &enemies){
	for (int i = 0; i < enemies.size(); i++){
		if (enemies[i].enemyMove(level)){

		}
	}
}

bool playerAttack(Level &level, Player &player, vector<Enemy> &enemies){
	int pX = player.getX();
	int pY = player.getY();
	bool fight = false;
	cout << "Player Health: " << player.getHealth() << "  Level: " << player.getLevel() << " Exp: " << player.getExp() << endl;
	for (int i = 0; i < enemies.size(); i++){
		int eX = enemies[i].getX();
		int eY = enemies[i].getY();
		
		if ((eX == pX + 1 && eY == pY) || (eX == pX - 1 && eY == pY) || (eX == pX && eY == pY + 1) || (eX == pX && eY == pY - 1)){
			fight = true;
			cout << "************BATTLE**************" << endl;
			cout << "Enemy Level : " << enemies[i].getLevel() << " Health: " << enemies[i].getHealth() << endl;
			enemies[i].defence(player.attack());
			player.defence(enemies[i].attack());

			if (player.getHealth() >= 1 && enemies[i].getHealth() >= 1){
				
			}
			else if (player.getHealth() >= 1 && enemies[i].getHealth() <= 0){
				cout << "Enemy Killed!" << endl;
				cout << player.getExp() << endl;
				player.addExp(enemies[i].getLevel() * 50);
				cout << player.getExp() << endl;
				level.setThing(eX, eY, '.');
				enemies[i] = enemies[enemies.size() - 1];
				enemies.pop_back();
			}
			else{
				cout << "You have died, game over";




				return false;
			}



		}
		else{
		}
	
	}
	if (!fight){
		cout << "No Nearby Enemies" << endl;
	}
	return true;

}
void enemyAttack(Level &level, vector<Enemy> &enemies){
	for (int i = 0; i < enemies.size(); i++){
		int X = enemies[i].getX();
		int Y = enemies[i].getY();
		for (int j = i + 1; j < enemies.size(); j++){
			int eX = enemies[j].getX();
			int eY = enemies[j].getY();
			if ((eX == X + 1 && eY == Y) || (eX == X - 1 && eY == Y) || (eX == X && eY == Y + 1) || (eX == X && eY == Y - 1)){
				cout << "enemy vs enemy" << endl;
				enemies[i].defence(enemies[j].attack());
				enemies[j].defence(enemies[i].attack());
				if (enemies[i].getHealth() >= 1 && enemies[j].getHealth() <= 0){
					enemies[i].addExp(enemies[j].getLevel() * 20);
					level.setThing(eX, eY, '.');
					enemies[j] = enemies[enemies.size() - 1];
					enemies.pop_back();
				}
				else if (enemies[j].getHealth() >= 1 && enemies[i].getHealth() <= 0){
					enemies[j].addExp(enemies[i].getLevel() * 20);
					level.setThing(X, Y, '.');
					enemies[i] = enemies[enemies.size() - 1];
					enemies.pop_back();
				}  
			}
		}
	}
}

