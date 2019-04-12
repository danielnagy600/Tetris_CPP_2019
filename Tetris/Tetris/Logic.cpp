#include "Logic.h"

Logic::Logic() :direction(0), colorNumber(0), elapsedTime(0), delay(0.5), a{0}, b{0}{}
Logic::~Logic(){}

void Logic::getEvent(sf::RenderWindow& window) {
	if (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed)window.close();
		else if (e.type == sf::Event::KeyPressed) {
			switch (e.key.code) {
			case sf::Keyboard::Down:
				delay = 0.03;
				break;
			case sf::Keyboard::Up:
				rotate();
				break;
			case sf::Keyboard::Left:
				direction = -1;
				break;
			case sf::Keyboard::Right:
				direction = 1;
				break;
			}
		}
	}
}

void Logic::setElapsedTime(float time) {
	elapsedTime += time;
}

void Logic::check(){
	bool orderly = true;

	for (int i = 0; i < 4; i++) {
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) orderly = false;
		else if (matrix[a[i].y][a[i].x] != 0) orderly = false;
	}

	if (!orderly) {
		for (int i = 0; i < 4; i++)a[i] = b[i];
	}
}

void Logic::move(){
	for (int i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += direction;
	}
	check();
}

void Logic::rotate(){
	Point p = a[1];
	for (int i = 0; i < 4; i++)
	{
		int x = a[i].y - p.y;
		int y = a[i].x - p.x;
		a[i].x = p.x - x;
		a[i].y = p.y + y;
	}
	check();
}

void Logic::setTetrominos(){
	if (elapsedTime > delay) {
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].y += 1;
		}

		bool orderly = true;
		for (int i = 0; i < 4; i++) {
			if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) orderly = false;
			else if (matrix[a[i].y][a[i].x] != 0) orderly = false;
		}


		if (!orderly) {
			for (int i = 0; i < 4; i++) {
				matrix[b[i].y][b[i].x] = colorNumber;
			}


			colorNumber = rand() % 7 + 1;
			int n = rand() % 7;
			for (int i = 0; i < 4; i++) {
				a[i].x = tetriminos[n][i] % 2;
				a[i].y = tetriminos[n][i] / 2;
			}
		}
		elapsedTime = 0;
	}
}

void Logic::rowBlasting(){

	int k = M - 1;
	for (int i = k; i > 0; i--) {
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j]) count++;
			matrix[k][j] = matrix[i][j];
		}
		if (count < N) k--;
	}
}

void Logic::end(sf::RenderWindow& window) {
	for (int i = 0; i < N; i++) {
		if (matrix[0][i] && matrix[1][i] && matrix[2][i] && matrix[3][i] && matrix[4][i])window.close();
	}
}



