#include "tile_boulder.h"
tile_boulder::tile_boulder(bool side)
{
	player = side;
	alive = 1;
	already_moved = 0;
	circle.setRadius(25.f);
	circle.setPointCount(100);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	circle.setPosition(2000, 2000);

	sf::Texture* texture_tile = new sf::Texture;

	if (side == 0)
	{
		texture_tile->loadFromFile("texture_boulder_2.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
	}
	if (side == 1)
	{
		texture_tile->loadFromFile("texture_boulder_1.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
	}
}

int tile_boulder::get_type()
{
	return 6;
}

void tile_boulder::unmark()
{
	circle.setOutlineColor(sf::Color::White);
}

tile_boulder::~tile_boulder() {}

