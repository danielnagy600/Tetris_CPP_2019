#ifndef _LOGIC_
#define _LOGIC_

#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>

const int M = 20;
const int N = 10;

class Logic {
	friend class Draw;
private:
	sf::Event e;
	int direction;
	int colorNumber;
	int scores;
	float elapsedTime;
	float delay;

	int matrix[M][N] = { 0 };

	struct Point {
		int x;
		int y;
	} a[4], b[4];

	int tetriminos[7][4] = {
		0,2,4,6, 
		0,1,2,4, 
		0,2,4,5, 
		0,1,2,3, 
		0,2,3,5, 
		1,2,3,4, 
		0,2,3,4, 
	};

public:
	Logic();
	~Logic();
	void getEvent(sf::RenderWindow&);
	void waiting();
	void move();
	void rotate();
	void setTetrominos();
	int rowBlasting();
	void check();
	void setElapsedTime(float);
	inline void  resetParameters() { direction = 0; delay = 0.5; };
	void end(sf::Sprite& s,sf::RenderWindow&);
};

#endif
