/*  PONG CLONE 
	Uses SFML (Believe it or not)
*/


#include "Game.h"

int main()
{
	Game *game = new Game;
	if (!game->init()){
		return -1;
	}
	return 0;
}
