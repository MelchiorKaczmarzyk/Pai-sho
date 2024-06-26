#include "tile_air.h"

tile_air::tile_air(bool side)
{
	player = side;
	alive = 1;
	circle.setRadius(25.f);
	circle.setPointCount(100);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::Texture* texture_tile = new sf::Texture;

	if (side == 0)
	{
		texture_tile->loadFromFile("texture_air_2.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color::Black);
	}
	if (side == 1)
	{
		texture_tile->loadFromFile("texture_air_1.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color(222, 168, 98));
	}
}

int tile_air::get_type()
{
	return 1;
}

void tile_air::unmark()
{
	if (player == 1)
		circle.setOutlineColor(sf::Color(222, 168, 98));
	if (player == 0)
		circle.setOutlineColor(sf::Color::Black);
}

tile_air::~tile_air() {}
