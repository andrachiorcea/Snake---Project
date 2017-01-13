#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <SFML/Graphics.hpp>
#include "Screen.h"

namespace Joc
{
	class Instructions : public Screen
	{
	public:
		Instructions();
		void handleInput(sf::RenderWindow& window)override;
		void update(sf::Time delta) override;
		void Draw(sf::RenderWindow& window) override;

	private:
		sf::Font font;
		sf::Text text;
	};
}

#endif