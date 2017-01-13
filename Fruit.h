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
		void Fruit::setPosition(int x,int y);
        sf::FloatRect getBounds();
		void setGreen();
		void setRed();
	private:
		sf::RectangleShape fruit;
        static const float lat;
		sf::Texture text;
	};
}

#endif
