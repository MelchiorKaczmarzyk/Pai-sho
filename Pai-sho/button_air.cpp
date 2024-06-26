#include "button_air.h"

button_air::button_air(bool player1)
{
	//ten rozmiar pionków i guzików będziesz musiał dostosować jeszcze
	hitbox = new sf::CircleShape(25.f,100);
	hitbox->setOrigin(hitbox->getRadius(), hitbox->getRadius());

	borderx = hitbox->getPosition().x + hitbox->getRadius();
	bordery = hitbox->getPosition().y + hitbox->getRadius();
	border_x = hitbox->getPosition().x - hitbox->getRadius();
	border_y = hitbox->getPosition().y - hitbox->getRadius();

	sf::Texture* texture_button = new sf::Texture;

	player = player1;
	if (player == 0)
	{
		texture_button->loadFromFile("texture_air_2.png");
		hitbox->setTexture(texture_button);
		hitbox->setOutlineThickness(2.6);
		hitbox->setOutlineColor(sf::Color::Black);
	}
	if (player == 1)
	{
		texture_button->loadFromFile("texture_air_1.png");
		hitbox->setTexture(texture_button);
		hitbox->setOutlineThickness(3);
		hitbox->setOutlineColor(sf::Color(222, 168, 98));
	}
}

sf::CircleShape* button_air::get_hitbox()
{
	return hitbox;
}

tile* button_air::trigger(board board1)
{
	tile* result = new tile_air(player);
	if (player == 0)
		if (board1.get_tab()[30][8]->get_tile() == nullptr)
		{
			board1.get_tab()[30][8]->assign_tile(result);
			result->put(board1.get_tab()[30][8]->get_position());

			hitbox->setRadius(0);
			borderx = hitbox->getPosition().x + hitbox->getRadius();
			bordery = hitbox->getPosition().y + hitbox->getRadius();
			border_x = hitbox->getPosition().x - hitbox->getRadius();
			border_y = hitbox->getPosition().y - hitbox->getRadius();
			return result;
		}
	if (player == 1)
		if (board1.get_tab()[2][8]->get_tile() == nullptr)
		{
			board1.get_tab()[2][8]->assign_tile(result);
			result->put(board1.get_tab()[2][8]->get_position());

			hitbox->setRadius(0);
			borderx = hitbox->getPosition().x + hitbox->getRadius();
			bordery = hitbox->getPosition().y + hitbox->getRadius();
			border_x = hitbox->getPosition().x - hitbox->getRadius();
			border_y = hitbox->getPosition().y - hitbox->getRadius();
			return result;
		}
	return nullptr;
}

void button_air::put(sf::Vector2f position1)
{
	hitbox->setPosition(position1);
	borderx = hitbox->getPosition().x + hitbox->getRadius();
	bordery = hitbox->getPosition().y + hitbox->getRadius();
	border_x = hitbox->getPosition().x - hitbox->getRadius();
	border_y = hitbox->getPosition().y - hitbox->getRadius();
}


