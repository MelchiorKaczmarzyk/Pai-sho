#include "button_text.h"


button_text::button_text(bool player1)
{
	hitbox = new sf::RectangleShape({ 300, 100 });
	hitbox->setOrigin({ 150, 50 });
	borderx = hitbox->getPosition().x + 150;
	bordery = hitbox->getPosition().y + 50;
	border_x = hitbox->getPosition().x - 150;
	border_y = hitbox->getPosition().y - 50;

	player = player1;

	if (player == 1)
	{
		hitbox->setFillColor(sf::Color::White);
		hitbox->setOutlineThickness(7);
		hitbox->setOutlineColor(sf::Color::Black);
		put({ 830, 750 });
	}

	if (player == 0)
	{
		hitbox->setFillColor(sf::Color::Black);
		hitbox->setOutlineThickness(7);
		hitbox->setOutlineColor(sf::Color::White);
		put({ 250, 750 });
	}
}

sf::RectangleShape* button_text::get_hitbox()
{
	return hitbox;
}

void button_text::put(sf::Vector2f position1)
{
	hitbox->setPosition(position1);
	borderx = hitbox->getPosition().x + 100;
	bordery = hitbox->getPosition().y + 50;
	border_x = hitbox->getPosition().x - 100;
	border_y = hitbox->getPosition().y - 50;
}

void button_text::reset()
{
	if (player == 1)
	{
		hitbox->setOutlineColor(sf::Color::Black);
	}
	else
	{
		hitbox->setOutlineColor(sf::Color::White);
	}
}

/*
std::string button_text::trigger()
{
	std::string nick;
	std::regex nick_template("[A-Z]{,10}");
	sf::Text text;
	bool correct = 0;

	
	correct = std::regex_match(nick, nick_template);

}
*/
