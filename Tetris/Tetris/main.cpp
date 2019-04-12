#include <SFML/Graphics.hpp>
#include "Logic.h"
#include "Draw.h"

#include <iostream>

int main() {
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(300, 400), "Tetris");

	sf::Texture t1;
	sf::Texture t2;

	t1.loadFromFile("images/tiles.png");
	t2.loadFromFile("images/background.png");

	sf::Sprite s(t1);
	sf::Sprite background(t2);

	sf::Clock clock;
	float time;

	Draw draw;
	Logic gameLogic;

	while (window.isOpen()) {
		gameLogic.getEvent(window);
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		gameLogic.setElapsedTime(time);
		gameLogic.move();
		gameLogic.rotate();
		gameLogic.setTetrominos();
		gameLogic.rowBlasting();
		gameLogic.resetParameters();
		window.draw(background);
		draw.drawing(gameLogic, window, s);
		window.display();
		gameLogic.end(window);
	}
	return 0;
}


/*
HIBÁK:
	1.  Fantom sprite
	2.  3-as okat Pörgeti mint -> 3x3-as területen
	3.  4-es nem is engedi mozgatni
	//Nála a Rotate egy bool paraméter volt nálam egy függvény ami sokszor meghívódik

*/
