#ifndef _DRAW_
#define _DRAW_
#include <SFML/Graphics.hpp>
#include "Logic.hpp"

class Draw {

public:
	Draw();
	~Draw();
	void drawing(Logic&,sf::RenderWindow&,sf::Sprite&, sf::Text&, sf::Text&,int );
};

#endif

