#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <string>
#include <regex>;
#include "button_text.h"

class menu
{
private:
	sf::RenderWindow* window;
	sf::Vector2i cursor_position;
	sf::RectangleShape* background;
	sf::Texture* texture;
	button_text* button1;
	button_text* button2;
	std::string name1;
	std::string name2;
	int border;

public:
	menu();
	sf::Vector2<std::string>* activate();
};

