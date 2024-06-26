#include "tile_fire.h"

tile_fire::tile_fire(bool side)
{
	player = side;
	alive = 1;
	circle.setRadius(25.f);
	circle.setPointCount(100);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	sf::Texture* texture_tile = new sf::Texture;

	if (side == 0)
	{
		texture_tile->loadFromFile("texture_fire_2.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color::Black);
	}
	if (side == 1)
	{
		texture_tile->loadFromFile("texture_fire_1.png");
		texture_tile->setSmooth(1);
		circle.setTexture(texture_tile);
		circle.setOutlineThickness(3);
		circle.setOutlineColor(sf::Color(173, 9, 9));
	}
}

void tile_fire::unmark()
{
	if (player == 1)
		circle.setOutlineColor(sf::Color(173, 9, 9));
	if (player == 0)
		circle.setOutlineColor(sf::Color::Black);
}

int tile_fire::get_type()
{
	return 4;
}

tile_fire::~tile_fire() {}
