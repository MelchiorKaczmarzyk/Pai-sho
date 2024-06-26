#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <vector>
#include "tile.h"
#include "tile_lotus.h"
#include "tile_air.h"
#include "tile_water.h"
#include "tile_earth.h"
#include "tile_fire.h"
#include "tile_boulder.h"
#include "tile_thorn.h"
#include "place.h"
#include "place_index.cpp"


class board
{
private:
	sf::Vector2f center;
	sf::CircleShape circle;
	std::vector<std::vector<place*>> tab;
	float unit;

public:
	board();
	~board();
	std::vector<std::vector<place*>> get_tab();
	sf::CircleShape get_circle();

	place_index* find_tile(sf::Vector2i v);
	bool move_tile(sf::Vector2i v, place_index* pi);
	bool move_tile(sf::Vector2i v, tile* tile1);

	bool thorned(int row, int column);
	bool harmony(bool player1);
	bool harmony2(bool player1);
	void show_moves(place_index* pi);
	void show_moves(int type1);

	void hide_moves();
	bool check_position(sf::Vector2i v);
	void make_place();
	void fill();
	void draw_tiles(sf::RenderWindow* window);

};

