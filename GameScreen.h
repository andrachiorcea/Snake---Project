#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"
#include"Bub.h"

namespace Joc
{
	class GameScreen : public Screen
	{
	public:
		GameScreen();
		void handleInput(sf::RenderWindow& window) override ;
		void update(sf::Time delta) override;
		void Draw(sf::RenderWindow& window) override;
		void newFruit();
		void Berry();
		void Scorx5();
		void increaseSpeed();
		void newBub();

	private:
		Snake snake;
		Fruit fruit;
		Bub bub;
	};
}

#endif