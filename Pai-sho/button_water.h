#pragma once
#include "button.h"
class button_water : public button
{
private:
	sf::CircleShape* hitbox;

public:
	button_water(bool player1);
	sf::CircleShape* get_hitbox();
	tile* trigger(board board1);
	void put(sf::Vector2f position1);
};

