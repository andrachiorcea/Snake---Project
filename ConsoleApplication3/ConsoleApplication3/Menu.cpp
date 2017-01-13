#include <SFML/Graphics.hpp>
#pragma warning(disable: 4996)
#include "GameScreen.h"
#include "Menu.h"
#include"Instructions.h"
#include "Game.h"

using namespace Joc;
Menu::Menu()
{
	font.loadFromFile("font.ttf");
	options.setFont(font);
	options.setString(
		"Apasa S pentru a incepe jocul"
		"\nApasa I pentru a citi instructiunile"
		"\nApasa ESC pentru a parasi jocul"
	);
	options.setColor(sf::Color(153, 79, 79));
	Title.setFont(font);
	Title.setString("Jocul SNAKE");
	Title.setColor(sf::Color(255, 102, 102));
	options.setCharacterSize(25);
	Title.setCharacterSize(75);
	options.setPosition(Game::Width -610, Game::Height / 2+20);
	Title.setPosition(Game::Width -580, Game::Height / 4);

}

void Menu::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Game::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		Game::Screen = std::make_shared<Instructions>();
	
}

void Menu::update(sf::Time delta)
{
}

void Menu::Draw(sf::RenderWindow& window)
{
	window.draw(options);
	window.draw(Title);
}
