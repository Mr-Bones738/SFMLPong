#ifndef H_PADDLE
#define H_PADDLE

#include <SFML/Graphics.hpp>

class Paddle{
public:
	bool init(sf::RenderWindow *window);
	void render(sf::RenderWindow *window);
	void move(float speedy);
	sf::Texture tx_paddle;
	sf::Sprite sp_paddle;
};

#endif