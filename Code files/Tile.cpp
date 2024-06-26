#include "tile.h"
#include <iostream>

sf::CircleShape tile::get_circle()
{
	return circle;
}

void tile::put(sf::Vector2f v1)
{
	circle.setPosition(v1);
	borderx = circle.getPosition().x + circle.getRadius();
	bordery = circle.getPosition().y + circle.getRadius();
	border_x = circle.getPosition().x - circle.getRadius();
	border_y = circle.getPosition().y - circle.getRadius();
}

void tile::put(sf::Vector2i v1)
{
	circle.setPosition(static_cast<float>(v1.x), static_cast<float>(v1.y));
	borderx = circle.getPosition().x + circle.getRadius();
	bordery = circle.getPosition().y + circle.getRadius();
	border_x = circle.getPosition().x - circle.getRadius();
	border_y = circle.getPosition().y - circle.getRadius();
}

void tile::mark()
{
	circle.setOutlineColor(sf::Color::Green);
}

void tile::mark2()
{
	if (circle.getOutlineThickness() != 3)
		circle.setOutlineThickness(3);
		
	circle.setOutlineColor(sf::Color::Magenta);
}

void tile::unmark()
{

}

void tile::harmonise()
{
	harmonised = 1;
}

void tile::deharmonise()
{
	harmonised = 0;
}