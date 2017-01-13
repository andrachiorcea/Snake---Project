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
	Bub(bub);
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
		Berry();
		if (snake.score() % 4 == 0) newBub();
	}
	Scorx5();
	if (snake.eatsp(bub) == true) {
		bub.setPosition(-1000, -1000);
		snake.Shrink();
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
	bub.Draw(window);
}

void GameScreen::newFruit()
{
	static default_random_engine engine;
	engine.seed(time(NULL));
	static uniform_int_distribution<int> xDistribution(15, Game::Width - 15);
	static uniform_int_distribution<int> yDistribution(15, Game::Height - 15);
	fruit.setPosition(xDistribution(engine), yDistribution(engine));
}

void Joc::GameScreen::Berry()
{
	if (snake.score() % 10 == 0) {
		fruit.setBerry();
	}
	else {
		fruit.setApple();
	}
}

void Joc::GameScreen::Scorx5()
{
	if (snake.score() % 11 == 0) 
		{
			snake.grow();
			snake.grow();
			snake.grow();
			snake.grow();
		}
	
}

void Joc::GameScreen::increaseSpeed()
{
     snake.move();
}

void Joc::GameScreen::newBub()
{
		bub.setPosition(rand()%300, rand()%300);
}

