#include <SFML/Graphics.hpp>

#include "Cell.h"

using namespace Joc;

const float Cell::l = 15.f;


Cell::Cell(sf::Vector2f position)
{
	pos = position;
	cell.setPosition(pos);
	cell.setFillColor(sf::Color(255, 102, 102));
	cell.setSize(sf::Vector2f(Cell::l, Cell::l));
	cell.setOutlineColor(sf::Color::Black);
	cell.setOutlineThickness(-1.f);
}
void Cell::SetColor()
{
	cell.setFillColor(sf::Color::White);
}

void Cell::setPosition(float x, float y)
{
	pos.x = x;
	pos.y = y;
	cell.setPosition(pos);
}

void Cell::move(float x1, float y1)
{
	pos.x =pos.x+ x1;
	pos.y =pos.y+ y1;
	cell.setPosition(pos);
}

sf::FloatRect Cell::getBounds() const
{
	return cell.getGlobalBounds();
}

sf::Vector2f Cell::getPosition() const
{
	return pos;
}

void Cell::Draw(sf::RenderWindow& window)
{
	window.draw(cell);
}