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
        sf::FloatRect getBounds() ;
	private:
		sf::CircleShape fruit;
        static const float radius;
	};
}

#endif
