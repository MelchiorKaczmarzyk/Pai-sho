#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <iostream>
#include "board.h"
class button
{
public:
	bool player;
	bool draw = 1;
	float borderx;
	float bordery;
	float border_x;
	float border_y;

	virtual sf::CircleShape* get_hitbox() = 0;
	virtual tile* trigger(board board1) = 0;
	virtual void put(sf::Vector2f position1) = 0;
};

