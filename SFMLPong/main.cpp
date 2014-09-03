/*  PONG CLONE 
	Uses SFML
	Give your compiler the 32 bit dynamic libraries and includes
	Give the exe the DLLs
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