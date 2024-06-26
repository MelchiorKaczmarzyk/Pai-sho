#include "tile_earth.h"

tile_earth::tile_earth(bool side)
{
	player = side;
	alive = 1;
	circle.setRadius(25.f);
	circle.setPointCount(100);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::Texture* texture_tile = new sf::Texture;

	if (side == 0)
	{
		texture_tile->loadFromFile("texture_earth_2.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color::Black);
	}
	if (side == 1)
	{
		texture_tile->loadFromFile("texture_earth_1.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color(10, 84, 4));
	}
}

void tile_earth::unmark()
{
	if (player == 1)
		circle.setOutlineColor(sf::Color(10, 84, 4));
	if (player == 0)
		circle.setOutlineColor(sf::Color::Black);
}

int tile_earth::get_type()
{
	return 3;
}

tile_earth::~tile_earth() {}
