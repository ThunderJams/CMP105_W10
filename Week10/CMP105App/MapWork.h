#pragma once
#include "Framework/TileMap.h"
#include <SFML/Graphics.hpp>

class MapWork
{
public:
	MapWork(sf::RenderWindow* hwnd);
	~MapWork();

	void renderMap();

private:
	sf::RenderWindow* window;
	TileMap tileMap;
};

