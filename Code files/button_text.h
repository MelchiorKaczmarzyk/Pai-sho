#pragma once
#include "button.h";

class button_text
{
private:
	sf::RectangleShape* hitbox;

public:
	bool player;
	float borderx;
	float bordery;
	float border_x;
	float border_y;

	button_text(bool player1);
	sf::RectangleShape* get_hitbox();
	void reset();
	void put(sf::Vector2f position1);
};

