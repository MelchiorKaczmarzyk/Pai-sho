#include "button_manager.h"	

button_manager::button_manager()
{

}

std::vector<button*> button_manager::get_buttons()
{
	return buttons;
}

void button_manager::fill(bool player1)
{
	sf::Vector2f position;
	int mod;

	if (player1 == 1)
	{
		position = { 40, 74 };
		mod = 1;
	}
	else
	{
		position = { 1040, 926 };
		mod = -1;
	}

	buttons.push_back(new button_air(player1));
	buttons.push_back(new button_air(player1));
	buttons[0]->put(position);
	buttons[1]->put({ position.x, position.y + 10 * mod });

	buttons.push_back(new button_thorn(player1));
	buttons.push_back(new button_thorn(player1));
	buttons[2]->put({position.x, position.y + 75 * mod});
	buttons[3]->put({ position.x, position.y + 85 * mod });

	position.x += 65*mod;

	buttons.push_back(new button_water(player1));
	buttons.push_back(new button_water(player1));
	buttons[4]->put(position);
	buttons[5]->put({ position.x, position.y + 10 * mod });

	buttons.push_back(new button_boulder(player1));
	buttons.push_back(new button_boulder(player1));
	buttons[6]->put({ position.x, position.y + 75 * mod });
	buttons[7]->put({ position.x, position.y + 85 * mod });

	position.x += 65 * mod;

	buttons.push_back(new button_earth(player1));
	buttons.push_back(new button_earth(player1));
	buttons[8]->put(position);
	buttons[9]->put({ position.x, position.y + 10 * mod });

	position.x += 65 * mod;

	buttons.push_back(new button_fire(player1));
	buttons.push_back(new button_fire(player1));
	buttons[10]->put(position);
	buttons[11]->put({ position.x, position.y + 10 * mod });
}

void button_manager::remove(int index)
{
	buttons[index]->draw = 0;
}

