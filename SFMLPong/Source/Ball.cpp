#include "Ball.h"
#include <time.h>
bool Ball::init(sf::RenderWindow *window){
	srand(time(NULL));
	speedx = rand() % 5+1;
	speedy = rand() % 5+0.1f;
	if (!tx_ball.create(32,32)){
		return false;
	}
	speed = sf::Vector2f(0.f, 0.f);
	if(!tx_ball.loadFromFile("Assets/ball.png")||
	!buf_beep.loadFromFile("Assets/beep.ogg")||
	!buf_boop.loadFromFile("Assets/boop.ogg")){
		return false;	
	}
	beep.setBuffer(buf_beep);
	boop.setBuffer(buf_boop);
	tx_ball.setSmooth(false);
	sp_ball.setTexture(tx_ball);
	sp_ball.setOrigin(sf::Vector2f(16,16));
	sp_ball.setPosition(sf::Vector2f(500,250));
	return true;
}

void Ball::update(sf::RenderWindow *window, Paddle *paddle, Paddle *paddle2, Score *score){
	float paddle1topedge = paddle->sp_paddle.getPosition().y + 64;
	float paddle1bottomedge = paddle->sp_paddle.getPosition().y - 64;
	float paddle1rightedge = paddle->sp_paddle.getPosition().x + 8;
	float paddle1leftedge = paddle->sp_paddle.getPosition().x - 8;
	float paddle2topedge = paddle2->sp_paddle.getPosition().y + 64;
	float paddle2bottomedge = paddle2->sp_paddle.getPosition().y - 64;
	float paddle2rightedge = paddle2->sp_paddle.getPosition().x + 8;
	float paddle2leftedge = paddle2->sp_paddle.getPosition().x - 8;
	float balltopedge = sp_ball.getPosition().y + 16;
	float ballbottomedge = sp_ball.getPosition().y - 16;
	float ballrightedge = sp_ball.getPosition().x + 16;
	float ballleftedge = sp_ball.getPosition().x - 16;

	if (balltopedge > 500 || ballbottomedge < 1){
		boop.play();
	speedy = speedy * -1.f;
		speed = sf::Vector2f(speedx, speedy);
	}
	if (ballleftedge < 1){
		srand(time(NULL));
		speedx = rand() % 5+1;
		speedy = rand() % 5+0.1f;
		speed = sf::Vector2f(0.f, 0.f);
		sp_ball.setPosition(sf::Vector2f(500.f, 250.f));
		score->player2score++;
	}
	if (ballrightedge > 1000){
		srand(time(NULL));
		speedx = rand() % 5 + 1;
		speedy = rand() % 5 + 0.1f;
		speed = sf::Vector2f(0.f, 0.f);
		sp_ball.setPosition(sf::Vector2f(500.f, 250.f));
		score->player1score++;
	}
	if (ballleftedge <= paddle1rightedge && balltopedge > paddle1bottomedge && ballbottomedge < paddle1topedge) {
		speedx = (speedx * 1.3f) * -1.f;
		if (sp_ball.getPosition().y > paddle->sp_paddle.getPosition().y + 32){
			speedy = 2.f;
		}
		if (sp_ball.getPosition().y < paddle->sp_paddle.getPosition().y - 32){
			speedy = -2.f;
		}
		speed = sf::Vector2f(speedx, speedy);
		beep.play();
	}
	if (ballrightedge >= paddle2leftedge && balltopedge > paddle2bottomedge && ballbottomedge < paddle2topedge) {
		speedx = (speedx * 1.3f) * -1.f;
		if (sp_ball.getPosition().y > paddle2->sp_paddle.getPosition().y + 32){
			speedy = 2.f;
		}
		if (sp_ball.getPosition().y < paddle2->sp_paddle.getPosition().y - 32){
			speedy = -2.f;
		}
		speed = sf::Vector2f(speedx, speedy);
		beep.play();
	}
	sp_ball.move(speed);
	window->draw(sp_ball);
}
