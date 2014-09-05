#include "Paddle.h"

bool Paddle::init(sf::RenderWindow *window){
	if (!tx_paddle.loadFromFile("Assets/paddle.png")){
		return false;
	}
	tx_paddle.setSmooth(false);
	sp_paddle.setTexture(tx_paddle);
	sp_paddle.setOrigin(8, 64);
	return true;
}

void Paddle::render(sf::RenderWindow *window){
	window->draw(sp_paddle);
}

void Paddle::move(float speedy){
	sp_paddle.move(0.f, speedy);
	return;
}
