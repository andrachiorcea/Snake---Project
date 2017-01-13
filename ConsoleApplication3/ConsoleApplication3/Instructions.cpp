#include <SFML/Graphics.hpp>

#include <memory>
#pragma warning(disable: 4996)
#include "Menu.h"
#include "Instructions.h"
#include "Game.h"

using namespace Joc;
Instructions::Instructions()
{
	font.loadFromFile("font.ttf");
	text.setFont(font);
	text.setString(
		"Jocul consta intr-un sarpe \n(reprezentat initial \n printr-un patrat alb) \n care trebuie sa se deplaseze catre mar \n pentru a se mari si a castiga puncte.\n Sarpele se poate deplasa pe 4 directii\n (sus, jos, stanga, dreapta)  si \n va fi controlat cu ajutorul sagetilor.\n Jucatorul pierde in momentul in \n care  capul sarpelui se va intersecta\n cu  restul corpului. "
		"\n\n\nApasa B pentru a reveni la meniu."
		
	);
	text.setCharacterSize(25);
	text.setColor(sf::Color::White);
	text.setPosition(Game::Width / 17, Game::Height / 10);
}

void Instructions::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		Game::Screen = std::make_shared<Menu>();
}
void Instructions::update(sf::Time )
{
}

void Instructions::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}
