#include "Game.h"

int main(){
	sf::RenderWindow window(sf::VideoMode(325, 485), "Tetris");

	sf::Texture t,tb;
	t.loadFromFile("images/cubes.png");
	tb.loadFromFile("images/background.png");

	sf::Sprite s(t);
	sf::Sprite background(tb);
	s.setTextureRect(sf::IntRect(0,0,30,30));

	while (window.isOpen()){
		sf::Event e;
		while (window.pollEvent(e)){
			if (e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		window.draw(s);
		window.display();
	}
	return 0;
}