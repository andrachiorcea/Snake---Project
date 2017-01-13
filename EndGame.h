#ifndef END_GAME_H
#define END_GAME_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace Joc
{
	class EndGame : public Screen
	{
	public:
		EndGame(int score);
		void handleInput(sf::RenderWindow& window) override ;
		void update(sf::Time delta) override;
		void Draw(sf::RenderWindow& window) override;

	private:
		sf::Font font;
		sf::Text text;
		unsigned score;
	};
}

#endif