#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace Joc
{
	class Cell
	{
	public:
		Cell(sf::Vector2f position);
        void setPosition(float x, float y);
        void move(float x1, float y1);
		void Draw(sf::RenderWindow& window);
		sf::Vector2f getPosition() const;
		sf::FloatRect getBounds() const;
		void SetColor();
		static const float l;
		
	private:
		sf::RectangleShape cell;
		sf::Vector2f pos;
		
	};
}

#endif