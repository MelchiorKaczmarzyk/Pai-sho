#include "place.h"


place::place()
{
	move_type = 123;
	side = 0;
	borderx = 0;
	bordery = 0;
	border_x = 0;
	border_y = 0;
	drawn = 0;
	token = nullptr;
	region = 0;
}

place::place(int move_type1, int region1, sf::Vector2f position1)
{
	drawn = 0;
	side = 15.f;
	hitbox.setRadius(side);
	hitbox.setOrigin(sf::Vector2f(side, side));
	hitbox.setPosition(position1);
	token = nullptr;
	region = region1;
	position = position1;
	borderx = position1.x + side;
	bordery = position1.y +side;
	border_x = position1.x - side;
	border_y = position1.y - side;
	move_type = move_type1;

	hitbox.setFillColor(sf::Color(0, 255, 0, 128));
}

place::place(int region1, sf::Vector2f position1)
{
	drawn = 0;
	side = 15.f;
	hitbox.setRadius(side);
	hitbox.setOrigin(sf::Vector2f(side, side));
	hitbox.setPosition(position1);
	token = nullptr;
	region = region1;
	position = position1;
	borderx = position1.x + side;
	bordery = position1.y + side;
	border_x = position1.x - side;
	border_y = position1.y - side;
	if (region1 == 123)
	{
		move_type = 3;
	}
	if (region == 12)
	{
		move_type = 1;
	}
	if (region == 23)
	{
		move_type = 2;
	}
	if (region == 1 or region == 2 or region == 3 or region == 13)
	{
		move_type = 0;
	}

	hitbox.setFillColor(sf::Color(0, 255, 0, 128));
}

void place::blacken()
{
	hitbox.setFillColor(sf::Color::Black);
}

place::~place()
{

}
tile* place::get_tile()
{
	return token;
}

int place::get_region()
{
	return region;
}

sf::Vector2f place::get_position()
{
	return position;
}

sf::CircleShape place::get_hitbox()
{
	return hitbox;
}

float place::get_side()
{
	return side;
}

bool place::is_drawn()
{
	return drawn;
}

void place::set_drawn(bool bool1)
{
	drawn = bool1;
}

void place::set_position(sf::Vector2f v)
{
	hitbox.setPosition(v);
}

void place::assign_tile(tile* tile1)
{
	token = tile1;
}
