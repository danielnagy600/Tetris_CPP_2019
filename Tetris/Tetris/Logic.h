#pragma once
#include <SFML/Graphics.hpp>

const int M = 20;
const int N = 10;

class Logic {
	friend class Draw;
private:
	sf::Event e;
	int direction;
	int colorNumber;
	float elapsedTime;
	float delay;

	int matrix[M][N] = { 0 };

	struct Point {
		int x;
		int y;
	} a[4], b[4];

	int tetriminos[7][4] = {
		0,2,4,6, // I
		0,1,2,4, // J
		0,2,4,5, // L
		0,1,2,3, // O
		0,2,3,5, // S
		1,2,3,4, // Z
		0,2,3,4, // T
	};

public:
	Logic();
	~Logic();
	void getEvent(sf::RenderWindow& window);
	void move();
	void rotate();
	void setTetrominos();
	void rowBlasting();
	void check();
	void setElapsedTime(float);
	inline void  resetParameters() { direction = 0; delay = 0.5; };
	void end(sf::RenderWindow& window);


};

