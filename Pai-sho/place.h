#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include "tile.h"

class place
{
protected:
	tile* token;
	// 0 - empty, 1 - water, 2 - earth, 3 - fire, 12 - water and earth, 13 - water and fire, 23 - earth and fire, 123 - home
	int region;
	sf::Vector2f position;
	sf::CircleShape hitbox;
	float side;
	bool drawn;

public:
	float borderx;
	float bordery;
	float border_x;
	float border_y;
	// 0 - zwykłe pole, 1 - przekątna1, 2 - przekątna2, 3 - dom 
	int move_type;
	place();
	//NAPISZ O KONSTRUKTORACH!
	place(int region1, sf::Vector2f position1);
	place(int move_type1, int region1, sf::Vector2f position1);
	~place();
	void blacken();
	sf::CircleShape get_hitbox();
	tile* get_tile();
	int get_region();
	float get_side();
	sf::Vector2f get_position();
	bool is_drawn();
	void set_drawn(bool bool1);
	void set_position(sf::Vector2f v);
	void assign_tile(tile* tile1);
};

