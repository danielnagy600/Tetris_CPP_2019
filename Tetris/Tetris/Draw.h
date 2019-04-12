#pragma once
#include <SFML/Graphics.hpp>
#include "Logic.h"

class Draw {
private:

public:
	Draw();
	~Draw();

	void drawing(Logic& gameLogic, sf::RenderWindow& window, sf::Sprite& s);
};

