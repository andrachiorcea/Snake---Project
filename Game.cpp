#include <SFML/Graphics.hpp>

#include <memory>

#include "Menu.h"
#include "Game.h"

using namespace Joc;

const sf::Time Game::TimePerFrame = sf::seconds(1.f /10.f);

std::shared_ptr<Screen> Game::Screen = std::make_shared<Menu>();

Game::Game() :window(sf::VideoMode(Game::Width, Game::Height), "Snake")
{

}

void Game::handleInput(sf::RenderWindow& window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	Game::Screen->handleInput(window);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::Draw(sf::RenderWindow& window)
{
	window.clear();
	Game::Screen->Draw(window);
	window.display();
}

void Game::play()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;
		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput( window);
			update(TimePerFrame);
		}

		Draw(window);
	}
}