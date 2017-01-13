#include <SFML/Graphics.hpp>

#include <random>
#include <memory>
#include "GameScreen.h"
#include "EndGame.h"
#include "Game.h"

using namespace Joc;
using namespace std;

GameScreen::GameScreen() 
{
	Snake(snake);
	Fruit(fruit);
}

void GameScreen::handleInput(sf::RenderWindow& window)
{
	snake.handleInput();
}

void GameScreen::update(sf::Time delta)
{
	
	snake.update(delta);
	if (snake.eats(fruit) == true)
	{
		newFruit();
		snake.grow();
		FruitPower();
	}
	if (snake.dies() == true) {
		snake.update(delta);
		Game::Screen = std::make_shared<EndGame>(snake.score());
	}

}

void GameScreen::Draw(sf::RenderWindow& window)
{
	snake.Draw(window);
    fruit.Draw(window);
}

void GameScreen::newFruit()
{
	static default_random_engine engine;
	engine.seed(time(NULL));
	static uniform_int_distribution<int> xDistribution(0, Game::Width - 15);
	static uniform_int_distribution<int> yDistribution(0, Game::Height - 15);
	fruit.setPosition(xDistribution(engine), yDistribution(engine));
}

void Joc::GameScreen::FruitPower()
{
	if ((snake.score() - 1) % 10 == 0) fruit.setGreen();
	else fruit.setRed();
}
