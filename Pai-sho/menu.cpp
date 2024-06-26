#include "menu.h"

menu::menu()
{
	border = 1080;
	window = new sf::RenderWindow(sf::VideoMode(border, border), "Pai sho", sf::Style::Close);
	cursor_position = {0,0};

	background = new sf::RectangleShape({ 1080.f, 1080.f });
	background->setOrigin({ 540.f,540.f });
	background->setPosition(540.f, 500.f);

	texture = new sf::Texture;
	texture->loadFromFile("texture_menu.jpg");
	texture->setSmooth(1);
	background->setTexture(texture);

	button1 = new button_text(1);
	button2 = new button_text(0);
}

sf::Vector2<std::string>* menu::activate()
{
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Gabriola.ttf");
	std::regex name_template("[A-Z]{1}[a-z]{1,9}");
	sf::Text text1;
	text1.setFillColor(sf::Color::Black);
	text1.setFont(font);
	text1.setCharacterSize(50);
	text1.setPosition({ 710, 710 });
	text1.setStyle(sf::Text::Bold);
	sf::Text text2;
	text2.setFillColor(sf::Color::White);
	text2.setFont(font);
	text2.setCharacterSize(50);
	text2.setPosition({ 129, 710 });
	text2.setStyle(sf::Text::Bold);

	sf::Text greeting;
	greeting.setFillColor({ 207, 61, 25 });
	greeting.setOutlineColor({ 150, 43, 8 });
	greeting.setOutlineThickness(0.5);
	greeting.setFont(font);
	greeting.setCharacterSize(50);
	greeting.setPosition({ 280, 375 });
	greeting.setString("Who knocks at the garden gate?");
	greeting.setStyle(sf::Text::Bold);

	sf::Text answer1;
	answer1.setFillColor({ 207, 61, 25 });
	answer1.setOutlineColor({ 150, 43, 8 });
	answer1.setOutlineThickness(0.4);
	answer1.setFont(font);
	answer1.setCharacterSize(40);
	answer1.setPosition({ 355, 490 });
	answer1.setString("One who has eaten the fruit");
	answer1.setStyle(sf::Text::Bold);

	sf::Text answer2;
	answer2.setFillColor({ 207, 61, 25 });
	answer2.setOutlineColor({ 150, 43, 8 });
	answer2.setOutlineThickness(0.4);
	answer2.setFont(font);
	answer2.setCharacterSize(40);
	answer2.setPosition({ 393, 530 });
	answer2.setString("and tasted its mysteries");
	answer2.setStyle(sf::Text::Bold);

	bool ready1 = 0;
	bool ready2 = 0;
	bool READY = 0;
	bool clicked1 = 0;
	bool clicked2 = 0;
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				return new sf::Vector2<std::string>({ "","" });
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				cursor_position = sf::Mouse::getPosition(*window);

				if (clicked1 and !ready1)
				{
					name1.clear();
					text1.setString(name1);
					button1->reset();
					clicked1 = 0;
				}
				if (clicked2 and !ready2)
				{
					name2.clear();
					text2.setString(name1);
					button2->reset();
					clicked2 = 0;
				}

				if (!clicked1 or !clicked2)
				{
					if (button1->borderx > cursor_position.x and button1->border_x < cursor_position.x and button1->bordery > cursor_position.y and button1->border_y < cursor_position.y)
					{
						name1.clear();
						text1.setString(name1);
						button1->get_hitbox()->setOutlineColor(sf::Color::Green);
						clicked1 = 1;
						ready1 = 0;
						READY = 0;
					}
					if (button2->borderx > cursor_position.x and button2->border_x < cursor_position.x and button2->bordery > cursor_position.y and button2->border_y < cursor_position.y)
					{
						name2.clear();
						text2.setString(name2);
						button2->get_hitbox()->setOutlineColor(sf::Color::Green);
						clicked2 = 1;
						ready2 = 0;
						READY = 0;
					}
				}

				if (ready1 and ready2)
				{
					READY = 1;
				}
			}
			if (event.type == sf::Event::TextEntered)
			{
				if (clicked1)
				{
					if (name1.length() < 10)
					{
						name1 += event.text.unicode;
						text1.setString(name1);
					}
				}
				if (clicked2)
				{
					if (name2.length() < 10)
					{
						name2 += event.text.unicode;
						text2.setString(name2);
					}
				}
			}
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (clicked1)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						if (std::regex_match(name1, name_template))
						{
							button1->get_hitbox()->setOutlineColor(sf::Color::Magenta);
							ready1 = 1;
							clicked1 = 0;
						}
						else
						{
							button1->get_hitbox()->setOutlineColor(sf::Color::Red);
							name1.clear();
							text1.setString(name1);
							ready1 = 0;
							clicked1 = 0;
						}
					}
				}
				if (clicked2)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						if (std::regex_match(name2, name_template))
						{
							button2->get_hitbox()->setOutlineColor(sf::Color::Magenta);
							ready2 = 1;
							clicked2 = 0;
						}
						else
						{
							button2->get_hitbox()->setOutlineColor(sf::Color::Red);
							name2.clear();
							text2.setString(name2);
							ready2 = 0;
							clicked2 = 0;
						}
					}
				}
			}
			
			window->clear();
			window->draw(*background);
			window->draw(*button1->get_hitbox());
			window->draw(*button2->get_hitbox());
			window->draw(text1);
			window->draw(text2);
			window->draw(greeting);
			if (ready1 and ready2)
			{
				window->draw(answer1);
				window->draw(answer2);
			}
			window->display();

			if (READY)
			{
				window->close();
				return new sf::Vector2<std::string>({ name1, name2 });
			}
		}
	}
}


