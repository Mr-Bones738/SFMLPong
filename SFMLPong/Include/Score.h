#ifndef _H_SCORE
#define _H_SCORE

#include <SFML/Graphics.hpp>

class Score{
private:
	sf::Font font;
public:
	int player1score, player2score;
	std::string str_player1score, str_player2score;
	void init();
	void render(sf::RenderWindow *window);
	sf::Text tx_player1score;
	sf::Text tx_player2score;
};

#endif
