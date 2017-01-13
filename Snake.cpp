#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include<conio.h>
#include<Windows.h>
#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "Cell.h"
#include "EndGame.h"

using namespace Joc;


Snake::Snake()
{
	Head();
	dir = Start;
	dead = false;
}

void Snake::Head()
{
	cells.push_back(Cell(sf::Vector2f(Game::Width / 2,Game::Height /2)));
	cells[0].SetColor();
}

void Snake::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		dir =Up;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		dir= Down;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		dir= Left;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		dir= Right;
}

void Snake::update(sf::Time delta)
{
	move();
	hitWall();
	dies();
}

bool Snake::eats(Fruit fruit)
{
	for (int i = 0; i < cells.size(); i++)
	{
		if (cells[i].getBounds().intersects(fruit.getBounds())) return true;
	}
}

bool Joc::Snake::eatsp(Bub bub)
{
	for (int i = 0; i < cells.size(); i++)
	{
		if (cells[i].getBounds().intersects(bub.getBounds())) return true;
	}
}

void Snake::grow()
{
	switch (dir)
	{
	case Up:
		cells.push_back(Cell(sf::Vector2f(cells[cells.size() - 1].getPosition().x,
			cells[cells.size() - 1].getPosition().y + Cell::l)));
		break;
	case Down:
		cells.push_back(Cell(sf::Vector2f(cells[cells.size() - 1].getPosition().x,
			cells[cells.size() - 1].getPosition().y - Cell::l)));
		break;
	case Left:
		cells.push_back(Cell(sf::Vector2f(cells[cells.size() - 1].getPosition().x + Cell::l,
			cells[cells.size() - 1].getPosition().y)));
		break;
	case Right:
		cells.push_back(Cell(sf::Vector2f(cells[cells.size() - 1].getPosition().x - Cell::l,
			cells[cells.size() - 1].getPosition().y)));
		break;
	}
}

void Snake::ChangeColor()
{
	for (int i = 1; i < cells.size(); i++)
	{
		cells[i].SetColor();
	}
}


int Snake::score()
{
	return cells.size();
}

bool Joc::Snake::eatsBub(Bub bub)
{
	for (int i = 0; i < cells.size(); i++)
	{
		if (cells[i].getBounds().intersects(bub.getBounds())) return true;
	}
}

bool Snake::dies()
{
	Cell& headNode = cells[0];

	for ( int i = 1; i < cells.size(); ++i)
	{
		if (headNode.getBounds().intersects(cells[i].getBounds()))
		{
			dead = true;
		}
	}
	return dead;
}

void Snake::hitWall()
{
	if (cells[0].getPosition().x < 0)
		cells[0].setPosition(Game::Width, cells[0].getPosition().y);
	else if (cells[0].getPosition().x > Game::Width)
		cells[0].setPosition(0, cells[0].getPosition().y);
	else if (cells[0].getPosition().y < 0)
		cells[0].setPosition(cells[0].getPosition().x, Game::Height);
	else if (cells[0].getPosition().y > Game::Height)
		cells[0].setPosition(cells[0].getPosition().x, 0);
}

void Snake::move()
{
	for (int i =cells.size() - 1; i > 0; --i)
	{
		cells[i].setPosition(cells[i-1].getPosition().x, cells[i-1].getPosition().y);
	}

	switch (dir)
	{
	case Up:
		cells[0].move(0, -Cell::l);
		break;
	case Down:
		cells[0].move(0, Cell::l);
		break;
	case Left:
		cells[0].move(-Cell::l, 0);
		break;
	case Right:
		cells[0].move(Cell::l, 0);
		break;
	}
}

void Snake::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].Draw(window);
	}
}

void Snake::Shrink()
{
	cells.erase(cells.begin()+cells.size()/2, cells.end());
}