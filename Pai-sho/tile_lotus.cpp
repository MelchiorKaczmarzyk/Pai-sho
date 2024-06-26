#include "tile_lotus.h"
tile_lotus::tile_lotus(bool side)
{
	player = side;
	alive = 1;
	circle.setRadius(28.f);
	circle.setPointCount(100);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::Texture* texture_tile = new sf::Texture;

	if (side == 1)
	{
		texture_tile->loadFromFile("texture_lotus_2.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
	}
	if (side == 0)
	{
		texture_tile->loadFromFile("texture_lotus_1.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color::Black);
	}
}

int tile_lotus::get_type()
{
	return 0;
}

void tile_lotus::unmark()
{
	if (player == 1)
		circle.setOutlineColor(sf::Color::White);
	if (player == 0)
		circle.setOutlineColor(sf::Color::Black);
}

tile_lotus::~tile_lotus() {}