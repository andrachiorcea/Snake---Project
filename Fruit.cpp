#include <SFML/Graphics.hpp>

#include "Fruit.h"

using namespace Joc;

const float Fruit::radius = 10.f;


Fruit::Fruit(){
fruit.setPosition({ 20, 40 });
fruit.setRadius(Fruit::radius);
fruit.setFillColor(sf::Color::Red);
}

void Fruit::setPosition(int x, int y)
{
	fruit.setPosition(x,y);
}
void Fruit::Draw(sf::RenderWindow& window)
{
	window.draw(fruit);
}

sf::FloatRect Fruit::getBounds() 
{
	return fruit.getGlobalBounds();
}