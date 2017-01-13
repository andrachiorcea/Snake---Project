#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Cell.h"
#include "Fruit.h"
#include"Bub.h"

namespace Joc
{
	enum  Direction{Left, Right, Up, Down, Start};
	class Snake
	{
	public:
		Snake();

		void handleInput();
		void update(sf::Time delta);
		void Draw(sf::RenderWindow& window);
		void grow();
		bool eats(Fruit fruit);
		bool eatsp(Bub bub);
		void move();
		void hitWall();
		bool dies();
		void Head();
		bool dead;
		void ChangeColor();
		int score();
		bool eatsBub(Bub bub);
		void Shrink();
	private:
	
		Direction dir;
		std::vector<Cell> cells;
		static const int head=1;
	};
}

#endif