#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Screen.h"

namespace Joc
{
	class Game
	{
	public:
		Game();
		void play();
		void handleInput(sf::RenderWindow& window) ;
		void update(sf::Time delta);
		void Draw(sf::RenderWindow& window);

		static const int Width = 640;
		static const int Height = 480;

		static std::shared_ptr<Screen> Screen;

	private:
		sf::RenderWindow window;
		static const sf::Time TimePerFrame;
	};
}


#endif