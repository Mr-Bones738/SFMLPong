#ifndef H_GAME
#define H_GAME

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "Menu.h"

class Game{
public:
	sf::RenderWindow window();
	bool init();
	void render(sf::RenderWindow &window);
	Ball *ball;
	void input(sf::RenderWindow &window);
	Paddle *player1;
	Paddle *player2;
	Score *score;
	Menu *menu;
private:
	int windowWidth, windowHeight;
};

#endif