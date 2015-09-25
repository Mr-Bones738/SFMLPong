/*  PONG CLONE 
	Uses SFML (Believe it or not)
*/


#include "Game.h"

int main(int argc, char** argv){
	char ayy[] = "ayy lmao";
	Game *game = new Game;
	if (!game->init()){
		return -1;
	}
	return 0;
}
