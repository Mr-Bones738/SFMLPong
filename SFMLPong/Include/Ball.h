#ifndef _H_BALL
#define _H_BALL
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Score.h"
#include <SFML/Audio.hpp>

class Ball{
public:
	bool init(sf::RenderWindow *window);
	void update(sf::RenderWindow *window, Paddle *paddle1, Paddle *paddle2, Score *score);
	
	sf::Sprite sp_ball;
	float speedx;
	float speedy;
	sf::Vector2f speed;
private:
	sf::Texture tx_ball;
	sf::SoundBuffer buf_beep;
	sf::SoundBuffer buf_boop;
	sf::Sound beep;
	sf::Sound boop;
};

#endif
