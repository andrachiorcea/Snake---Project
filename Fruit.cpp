#include <SFML/Graphics.hpp>

#include "Fruit.h"

using namespace Joc;

const float Fruit::lat = 25.f;


Fruit::Fruit() {
	fruit.setPosition({ 20, 40 });
	fruit.setSize(sf::Vector2f(lat, lat));
	fruit.setFillColor(sf::Color::Red);
	text.loadFromFile("apple.jpeg");
	fruit.setTexture(&text);
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

void Joc::Fruit::setBerry()
{
	fruit.setFillColor(sf::Color::Magenta);
	text.loadFromFile("zmeura.jpg");
	fruit.setTexture(&text);
}

void Joc::Fruit::setApple()
{
	fruit.setFillColor(sf::Color(255, 51, 51));
	text.loadFromFile("apple.jpeg");
	fruit.setTexture(&text);
}
