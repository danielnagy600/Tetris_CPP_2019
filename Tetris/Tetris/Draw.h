#ifndef _DRAW_
#define _DRAW_
#include <SFML/Graphics.hpp>
#include "Logic.h"

class Draw {

public:
	Draw();
	~Draw();
	void drawing(Logic&,sf::RenderWindow&,sf::Sprite&);
};

#endif

