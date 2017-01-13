
#include <SFML/Graphics.hpp>

#include "Bub.h"
using namespace Joc;

const float Bub::lat = 25.f;


Bub::Bub() {
	bub.setPosition({1000,1000});
	bub.setSize(sf::Vector2f(lat, lat));
	bub.setFillColor(sf::Color::Red);
	text.loadFromFile("bub.jpg");
	bub.setTexture(&text);
}

void Bub::setPosition(int x, int y)
{
	bub.setPosition(x, y);
}
void Bub::Draw(sf::RenderWindow& window)
{
	window.draw(bub);
}

sf::FloatRect Bub::getBounds()
{
	return bub.getGlobalBounds();
}