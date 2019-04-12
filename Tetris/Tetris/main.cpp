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
	}
	return 0;
}


/*
HIBÁK:
	rózsaszin színû alakzat  szublimál- > ha 1-el kezdünk eltûnik
	Nincs vége a játéknak
	3-as okat Pörgeti mint a picsa -> 3x3-as területen
	4-es nem is engedi mozgatni
	//Nála a Rotate egy bool paraméter volt nálam egy függvény ami kurvasokszor mrghívódik

*/
