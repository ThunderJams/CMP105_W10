#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "MapWork.h"
#include "Mario.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, Mario* mar);
	~Level();

	void handleInput(float dt);
	void update(float dt, MapWork mapwork);
	void render(MapWork mapWork);

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	Mario* mario;
	
	sf::Texture marioTexture;
};