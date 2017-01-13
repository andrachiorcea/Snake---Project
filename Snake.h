#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Cell.h"
#include "Fruit.h"

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
		void move();
		void hitWall();
		bool dies();
		void Head();
		bool dead;
		void ChangeColor();
		int score();
		

	private:
	
		Direction dir;
		std::vector<Cell> cells;
		static const int head=1;
	};
}

#endif