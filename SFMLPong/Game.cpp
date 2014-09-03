#include "Game.h"

bool Game::init(){
	sf::RenderWindow window(sf::VideoMode(1000, 500), "420 bonglord yolo", sf::Style::Titlebar+sf::Style::Close);
	window.setFramerateLimit(60);
	menu = new Menu; // Menu.h Menu.cpp
	menu->init(&window);
	ball = new Ball; // Ball.h Ball.cpp
	player1 = new Paddle; // Paddle.h Paddle.cpp
	score = new Score; // Score.h Score.cpp
	score->init();
	score->tx_player1score.setPosition(sf::Vector2f(100.f, 0));
	score->tx_player2score.setPosition(sf::Vector2f(800.f, 0));
	if (!player1->init(&window)){
		window.close();
		return false;
	}
	player1->sp_paddle.setPosition(10, window.getSize().y / 2.f);
	player2 = new Paddle;
	if (!player2->init(&window)){
		window.close();
		return false;
	}
	player2->sp_paddle.setPosition(990, window.getSize().y / 2.f);
	if (!ball->init(&window)){
		window.close();
		return false;
	}
	while (window.isOpen()){
		render(window);
		input(window);
	}
	return 1;
}

void Game::render(sf::RenderWindow &window){
	window.clear(sf::Color::Black);
	ball->update(&window, player1, player2, score);
	player1->render(&window);
	player2->render(&window);
	score->render(&window);
	window.draw(ball->sp_ball);
	window.display();
}

void Game::input(sf::RenderWindow &window){
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type){
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code){
			case sf::Keyboard::Escape:
				window.close();
			case sf::Keyboard::Space:
				ball->speed = sf::Vector2f(ball->speedx, ball->speedy);
				break;
			}
		}
	}
	bool Wdown = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool Sdown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool UPdown = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	bool DOWNdown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	if (Wdown){
		if (player1->sp_paddle.getPosition().y-64.f <= 0){
			player1->sp_paddle.setPosition(player1->sp_paddle.getPosition().x, 0.f);
		}
		else{
			player1->move(-10);
		}
	}
	if (Sdown){
		if (player1->sp_paddle.getPosition().y+64.f >= 500){
			player1->sp_paddle.setPosition(player1->sp_paddle.getPosition().x, 500.f);
		}
		else{
			player1->move(10);
		}
	}
	if (UPdown){
		if (player2->sp_paddle.getPosition().y-64.f <= 0){
			player2->sp_paddle.setPosition(player2->sp_paddle.getPosition().x, 0.f);
		}
		else{
			player2->move(-10);
		}
	}
	if (DOWNdown){
		if (player2->sp_paddle.getPosition().y+64.f >= 500){
			player2->sp_paddle.setPosition(player2->sp_paddle.getPosition().x, 500.f);
		}
		else{
			player2->move(10);
		}
	}
}