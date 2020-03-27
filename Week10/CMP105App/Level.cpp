#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, Mario* mar)
{
	window = hwnd;
	input = in;
	mario = mar;

	// initialise game objects
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario->setInput(in);
	mario->setSize(sf::Vector2f(16, 21));
	mario->setPosition(200, 200);
	mario->setTexture(&marioTexture);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	mario->handleInput(dt);
}

// Update game objects
void Level::update(float dt, MapWork mapwork)
{
	mapwork.mapCollide();
	mario->update(dt);
}

// Render level
void Level::render(MapWork mapWork)
{
	beginDraw();
	mapWork.renderMap();
	window->draw(*mario);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}