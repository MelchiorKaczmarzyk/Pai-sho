#include "tile_water.h"
tile_water::tile_water(bool side)
{
	player = side;
	alive = 1;
	circle.setRadius(25.f);
	circle.setPointCount(100);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::Texture* texture_tile = new sf::Texture;

	if (side == 0)
	{
		texture_tile->loadFromFile("texture_water_2.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color::Black);
	}
	if (side == 1)
	{
		texture_tile->loadFromFile("texture_water_1.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color(9, 22, 143));
	}
}

void tile_water::unmark()
{
	if (player == 1)
		circle.setOutlineColor(sf::Color(9, 22, 143));
	if (player == 0)
		circle.setOutlineColor(sf::Color::Black);
}

int tile_water::get_type()
{
	return 2;
}

void tile_water::harmonise()
{
	if (harmonised1 == 1)
	{
		harmonised = 1;
	}
	if (harmonised1 == 0)
	{
		harmonised1 == 1;
	}
}

void tile_water::deharmonise()
{
	harmonised1 = 0;
	harmonised = 0;
}

tile_water::~tile_water() {}
