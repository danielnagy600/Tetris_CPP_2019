#include "Draw.h"

Draw::Draw() {}
Draw::~Draw() {}

void Draw::drawing(Logic& gameLogic, sf::RenderWindow& window, sf::Sprite& s) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (gameLogic.matrix[i][j]) {
				s.setTextureRect(sf::IntRect(gameLogic.matrix[i][j] * 18, 0, 18, 18));
				s.setPosition(j * 18, i * 18);
				s.move(10, 30);
				window.draw(s);
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		s.setTextureRect(sf::IntRect(gameLogic.colorNumber * 18, 0, 18, 18));
		s.setPosition(gameLogic.a[i].x * 18, gameLogic.a[i].y * 18);
		s.move(20, 30);
		window.draw(s);
	}


}

