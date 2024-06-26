#pragma once
#include "button.h"
class button_harmony : public button
{
private:
	sf::RectangleShape* hitbox;
	std::string name;

public:
	button_harmony();
	button_harmony(bool player1);
	void set_name(std::string name1);
	bool harmonise(board* board1);
	void reset();
	sf::RectangleShape* get_rectangle();
	void put(sf::Vector2f position);

	sf::CircleShape* get_hitbox();
	tile* trigger(board board1);
};

