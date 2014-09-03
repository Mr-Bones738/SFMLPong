#include "Score.h"
#include <sstream>

void Score::init(){
	player1score = 0;
	player2score = 0;
	font.loadFromFile("Assets/font.ttf");
	tx_player1score.setFont(font);
	tx_player2score.setFont(font);
	tx_player1score.setCharacterSize(100);
	tx_player2score.setCharacterSize(100);
	tx_player1score.setColor(sf::Color::White);
	tx_player2score.setColor(sf::Color::White);
	tx_player1score.setPosition(sf::Vector2f(100.f, 0));
	tx_player2score.setPosition(sf::Vector2f(800.f, 0));
}

void Score::render(sf::RenderWindow *window){
	std::ostringstream convert;
	convert << player2score;
	str_player2score = convert.str();
	convert.str("");
	convert << player1score;
	str_player1score = convert.str();
	tx_player1score.setString(str_player1score);
	tx_player2score.setString(str_player2score);
	window->draw(tx_player1score);
	window->draw(tx_player2score);
}