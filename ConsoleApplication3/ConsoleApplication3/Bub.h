#ifndef BUB_H
#define BUB_H

#include <SFML/Graphics.hpp>

namespace Joc
{
	class Bub
	{
	public:
		Bub();
		void Draw(sf::RenderWindow& window);
		void setPosition(int x, int y);
		sf::FloatRect getBounds();
	private:
		sf::RectangleShape bub;
		static const float lat;
		sf::Texture text;
	};
}

#endif
