#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

namespace Joc
{
	class Fruit
	{
	public:
		Fruit();
		void Draw(sf::RenderWindow& window);
		void setPosition(int x,int y);
        sf::FloatRect getBounds();
		void setBerry();
		void setApple();
	private:
		sf::RectangleShape fruit;
        static const float lat;
		sf::Texture text;
	};
}

#endif
