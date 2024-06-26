#pragma once
#include "place.h"
class place_tile: public place
{
public:
	tile* token;
	int region;
	sf::Vector2f position;
	sf::CircleShape hitbox;
	float side;

protected:
	place_tile(int region1, sf::Vector2f position1);
	place_tile(int region1, sf::Vector2f position1, tile* token1);
	sf::CircleShape get_hitbox();
	~place_tile();
	friend class board;
};

