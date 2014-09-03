#include "Menu.h"

bool Menu::init(sf::RenderWindow *window){
	font.loadFromFile("Assets/font.ttf");
	title.setFont(font);
	controls_player1.setFont(font);
	controls_player2.setFont(font);
	controls_game.setFont(font);
	title.setString(sf::String("PONG"));
	controls_player1.setString(sf::String("Player 1 uses W and S."));
	controls_player2.setString(sf::String("Player 2 uses Arrow Keys"));
	controls_game.setString(sf::String("Press enter/return to get rid of this screen and space to start the ball..."));
	title.setCharacterSize(100);
	controls_game.setCharacterSize(20);
	controls_player2.setCharacterSize(50);
	controls_player1.setCharacterSize(50);

	title.setPosition(window->getSize().x / 2 - 100, 0);
	controls_player1.setPosition(0, 200);
	controls_player2.setPosition(0, 300);
	controls_game.setPosition(0, 400);
	
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && window->isOpen()){
		render(window);
	}
	return true;
}

void Menu::render(sf::RenderWindow *window){
	window->clear(sf::Color::Black);
	window->draw(title);
	window->draw(controls_player1);
	window->draw(controls_player2);
	window->draw(controls_game);
	window->display();

	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type){
		case sf::Event::Closed:
			window->close();
			break;
		}
	}
}
