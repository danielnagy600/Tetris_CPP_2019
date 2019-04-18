#include <SFML/Graphics.hpp>
#include "Definitions.hpp"
#include "Logic.hpp"
#include "Draw.hpp"


int main() {
	srand(time(0));
	sf::Clock clock;
	Draw draw;
	Logic gameLogic;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), APPLICATION_NAME);
	sf::Texture t1, t2,t3,t4;

	sf::Text sc,scores;
	sc.setFillColor(sf::Color::White);
	scores.setFillColor(sf::Color::White);
	sc.Bold;
	scores.Bold;
	sc.setPosition(230,30);
	scores.setPosition(230,60);
	sc.setCharacterSize(20 );
	scores.setCharacterSize(20);
	sf::Font font;
	font.loadFromFile(FONT_NAME);
	sc.setFont(font);
	sc.setString("Scores");
	scores.setFont(font);


	t1.loadFromFile(TETROMINO_FILEPATH);
	t2.loadFromFile(BACKGROUND_FILEPATH);
	t3.loadFromFile(START_FILEPATH);
	t4.loadFromFile(END_FILEPATH);

	sf::Sprite s(t1);
	sf::Sprite background(t2);
	sf::Sprite start_screen(t3);
	sf::Sprite end_screen(t4);

	window.draw(start_screen);
	window.display();
	gameLogic.waiting();

	float time;
	int score;

	while (window.isOpen()) {
		gameLogic.getEvent(window);
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		gameLogic.setElapsedTime(time);
		gameLogic.move();
		gameLogic.setTetrominos();
		score=gameLogic.rowBlasting();
		gameLogic.resetParameters();
		window.draw(background);
		draw.drawing(gameLogic, window, s, sc,scores,score);
		window.display();
		gameLogic.end(end_screen,window);
		
	}
	return EXIT_SUCCESS;
}
