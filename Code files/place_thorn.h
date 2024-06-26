#pragma once
#include "place.h"
class place_thorn : public place
{
public:
	tile* token;
	int region;
	sf::Vector2f position;
	sf::RectangleShape hitbox;
	float side;

protected:
	place_thorn(int region1, sf::Vector2f position1);
	place_thorn(int region1, sf::Vector2f position1, tile* token1);
	sf::RectangleShape get_hitbox();
	~place_thorn();
	friend class board;
};

