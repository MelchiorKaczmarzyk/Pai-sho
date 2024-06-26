#include "button_boulder.h"
button_boulder::button_boulder(bool player1)
{
	hitbox = new sf::CircleShape(25.f, 100);
	hitbox->setOrigin(hitbox->getRadius(), hitbox->getRadius());

	borderx = hitbox->getPosition().x + hitbox->getRadius();
	bordery = hitbox->getPosition().y + hitbox->getRadius();
	border_x = hitbox->getPosition().x - hitbox->getRadius();
	border_y = hitbox->getPosition().y - hitbox->getRadius();

	sf::Texture* texture_button = new sf::Texture;

	player = player1;
	if (player == 0)
	{
		texture_button->loadFromFile("texture_boulder_2.png");
		hitbox->setTexture(texture_button);
	}
	if (player == 1)
	{
		texture_button->loadFromFile("texture_boulder_1.png");
		hitbox->setTexture(texture_button);
	}
}

sf::CircleShape* button_boulder::get_hitbox()
{
	return hitbox;
}

tile* button_boulder::trigger(board board1)
{
	tile* result = new tile_boulder(player);
	/*
	hitbox->setRadius(0);
	borderx = hitbox->getPosition().x + hitbox->getRadius();
	bordery = hitbox->getPosition().y + hitbox->getRadius();
	border_x = hitbox->getPosition().x - hitbox->getRadius();
	border_y = hitbox->getPosition().y - hitbox->getRadius();
	*/
	return result;
}

void button_boulder::put(sf::Vector2f position1)
{
	hitbox->setPosition(position1);
	borderx = hitbox->getPosition().x + hitbox->getRadius();
	bordery = hitbox->getPosition().y + hitbox->getRadius();
	border_x = hitbox->getPosition().x - hitbox->getRadius();
	border_y = hitbox->getPosition().y - hitbox->getRadius();
}
