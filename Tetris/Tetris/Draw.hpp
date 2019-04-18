#ifndef _DRAW_
#define _DRAW_
#include <SFML/Graphics.hpp>
#include "Logic.hpp"
#include "Definitions.hpp"

class Draw {

public:
	Draw();
	~Draw();
	void setFont(sf::Text&, sf::Text&,sf::Font&);
	void drawing(Logic&,sf::RenderWindow&,sf::Sprite&, sf::Text&, sf::Text&,int);
};

#endif

