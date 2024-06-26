#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>

class board;

class tile
{
protected:
	sf::CircleShape circle;


public:
	bool player;
	bool alive;
	bool already_moved;
	bool clicked;
	//NAPISZ O INICJUJĄCEJ WARTOŚCI
	bool harmonised = 0;
	float borderx;
	float bordery;
	float border_x;
	float border_y;

	bool victorious = 0;

	void mark();
	void mark2();

	//WYJAŚNIJ CZEMU 2
	void put(sf::Vector2f);
	void put(sf::Vector2i v1);

	virtual void unmark();
	virtual void harmonise();
	virtual void deharmonise();
	virtual int get_type() = 0;

	sf::CircleShape get_circle();
};



