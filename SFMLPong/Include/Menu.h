#ifndef _H_MENU
#define _H_MENU
#include <SFML/Graphics.hpp>

class Menu{
public:
	bool init(sf::RenderWindow *window);
	void render(sf::RenderWindow *window);
	sf::Text title;
	sf::Text controls_player1;
	sf::Text controls_player2;
	sf::Text controls_game;
	sf::Font font;
};

#endif
