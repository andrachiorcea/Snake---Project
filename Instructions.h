#ifndef INSTRUCTIONS_H
#define iNSTRUCTIONS_H

#include <SFML/Graphics.hpp>
#include "Screen.h"

namespace Joc
{
	class Instructions : public Screen
	{
	public:
		Instructions();
		void handleInput(sf::RenderWindow& window);
		void update(sf::Time delta);
		void Draw(sf::RenderWindow& window) ;

	private:
		sf::Font font;
		sf::Text text;
	};
}

#endif