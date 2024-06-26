#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include "button_manager.h"
#include "button_harmony.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Vector2i cursor_position;
	sf::RectangleShape* background;
	place_index* chosen_tile;
	button_manager buttons_board1;
	button_manager buttons_board2;
	button_harmony* bh1;
	button_harmony* bh2;
	board b;

	int border;
	bool player;
	bool moved;

	int counter1;
	int counter2;



public:
	Game();
	Game(sf::Texture* rug);
	void switch_player();
	bool play(sf::Vector2<std::string>* names);
};

