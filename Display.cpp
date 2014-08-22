#include "Display.h"


Display::Display(Level &level, Player &player)
{
	this->level = level;
	this->player = player;
}


Display::~Display()
{
}

void Display::printLevel(Player &player){
	for (int i = 0; i < level.getRows(); i++){

		for (int j = 0; j < level.getCols(); j++){
			std::cout << level.getThing(j, i);
		}
		/*if (i == 0){
			std::cout << " Player Information:";
		}
		else if (i == 1){
			std::cout << "----------------------";
		}
		else if (i == 2){
			std::cout << " Name:   " << player.getName() << " at ";
			player.printPosition();
		}
		else if (i == 3){
			std::cout << " Health: " << player.getHealth();
		}
		else{
		}*/
		std::cout << std::endl;
	}
	std::cout << std::endl;
}