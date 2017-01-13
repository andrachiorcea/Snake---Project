#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

class Screen
{
public:
	 virtual void handleInput(sf::RenderWindow& window);
	virtual void update(sf::Time delta) ;
	 virtual void Draw(sf::RenderWindow& window);

};

#endif