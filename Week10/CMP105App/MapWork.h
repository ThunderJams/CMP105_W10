#pragma once
#include "Framework/TileMap.h"
#include <SFML/Graphics.hpp>
#include "Framework/Collision.h"
#include "Mario.h"

class MapWork
{
public:
	MapWork(sf::RenderWindow* hwnd, Mario* mar);
	~MapWork();

	void renderMap();
	void mapCollide();
	

private:
	sf::RenderWindow* window;
	TileMap tileMap;
	Collision collision;
	Mario* mario;
};


