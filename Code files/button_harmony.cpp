#include "button_harmony.h"

button_harmony::button_harmony()
{

}

sf::RectangleShape* button_harmony::get_rectangle()
{
	return hitbox;
}

void button_harmony::put(sf::Vector2f position1)
{
	hitbox->setPosition(position1);
	borderx = hitbox->getPosition().x + 100;
	bordery = hitbox->getPosition().y + 50;
	border_x = hitbox->getPosition().x - 100;
	border_y = hitbox->getPosition().y - 50;
}

void button_harmony::set_name(std::string name1)
{
	name = name1;
}

button_harmony::button_harmony(bool player1)
{
	//zmieniaj rozmiar jak nie pasuje
	name = "1";
	hitbox = new sf::RectangleShape({ 200, 100 });
	hitbox->setOrigin({ 100, 50 });
	borderx = hitbox->getPosition().x + 100;
	bordery = hitbox->getPosition().y + 50;
	border_x = hitbox->getPosition().x - 100;
	border_y = hitbox->getPosition().y - 50;

	player = player1;

	if (player == 1)
	{
		hitbox->setFillColor(sf::Color::White);
		hitbox->setOutlineThickness(8.5);
		hitbox->setOutlineColor(sf::Color::Black);
		put({ 955, 65 });
	}

	if (player == 0)
	{
		hitbox->setFillColor(sf::Color::Black);
		hitbox->setOutlineThickness(8.5);
		hitbox->setOutlineColor(sf::Color::White);
		put({ 125, 925 });
	}
}

void button_harmony::reset()
{
	if (player == 1)
		hitbox->setOutlineColor(sf::Color::Black);
	if (player == 0)
		hitbox->setOutlineColor(sf::Color::White);
}

bool button_harmony::harmonise(board* board1)
{
	if (board1->harmony(player) or board1->harmony2(player))
	{
		hitbox->setOutlineColor(sf::Color::Magenta);
		return 1;
	}
	else
	{
		hitbox->setOutlineColor(sf::Color::Red);
		return 0;
	}
}

sf::CircleShape* button_harmony::get_hitbox()
{
	return nullptr;
}

tile* button_harmony::trigger(board board1)
{
	return nullptr;
}