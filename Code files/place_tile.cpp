#include "place_tile.h"


place_tile::place_tile(int region1, sf::Vector2f position1)
{
	side = 10;
	hitbox.setRadius(side);
	hitbox.setPointCount(50);
	token = nullptr;
	region = region1;
	position = position1;
	hitbox.setOrigin(side, side);

	hitbox.setFillColor(sf::Color(0, 255, 0, 128));
}

place_tile::place_tile(int region1, sf::Vector2f position1, tile* token1)
{
	side = 10;
	hitbox.setRadius(side);
	hitbox.setPointCount(50);
	token = token1;
	region = region1;
	position = position1;
	hitbox.setOrigin(side, side);

	hitbox.setFillColor(sf::Color(0, 255, 0, 128));
}

sf::CircleShape place_tile::get_hitbox()
{
	return hitbox;
}

place_tile::~place_tile() {};