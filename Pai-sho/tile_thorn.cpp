#include "tile_thorn.h"

tile_thorn::tile_thorn(bool side)
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
		texture_tile->loadFromFile("texture_thorn_22.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
	}
	if (side == 1)
	{
		texture_tile->loadFromFile("texture_thorn_1.png");
		circle.setTexture(texture_tile);
	}
}

int tile_thorn::get_type()
{
	return 5;
}

tile_thorn::~tile_thorn() {}
