#include <SFML/Graphics.hpp>
#pragma warning(disable: 4996)
#include <iostream>
#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "EndGame.h"

using namespace Joc;

EndGame::EndGame(int score)
{
	font.loadFromFile("font.ttf");
	text.setFont(font);
	text.setString("Scor: " + std::to_string(score-1 ) + "!"
		"\n\nApasa S pentru a mai juca o data"
		"\n\nApasa ESC pentru a parasi jocul");
	text.setColor(sf::Color(255, 102, 102));
	text.setPosition(50, Game::Height / 4);
}

void EndGame::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Game::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void EndGame::update(sf::Time delta)
{

}

void EndGame::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}