#include "place_thorn.h"


place_thorn::place_thorn(int region1, sf::Vector2f position1)
{
	side = 15;
	hitbox.setSize({side, side});
	token = nullptr;
	region = region1;
	position = position1;
	hitbox.setOrigin(side/2, side/2);

	hitbox.setFillColor(sf::Color(0, 255, 0, 128));
}

place_thorn::place_thorn(int region1, sf::Vector2f position1, tile* token1)
{
	side = 15;
	hitbox.setSize({ side, side });
	token = token1;
	region = region1;
	position = position1;
	hitbox.setOrigin(side / 2, side / 2);

	hitbox.setFillColor(sf::Color(0,255,0,128));
}

sf::RectangleShape place_thorn::get_hitbox()
{
	return hitbox;
}
place_thorn::~place_thorn() {};
