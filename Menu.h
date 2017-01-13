#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace Joc
{
	class Menu : public Screen
	{
	public:
		Menu();

		void handleInput(sf::RenderWindow& window) override;
		void update(sf::Time delta) ;
		void Draw(sf::RenderWindow& window) override;

	private:
		sf::Font font;
		sf::Text Title;
		sf::Text options;
	};
}

#endif