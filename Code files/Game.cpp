#include "Game.h"


void wait(int time)
{
    std::chrono::milliseconds timespan(time);
    std::this_thread::sleep_for(timespan);
}


Game::Game()
{
    border = 1080;
    window = new sf::RenderWindow(sf::VideoMode(border, border), "Pai sho", sf::Style::Close);
    window->close();

    b.make_place();
    b.fill();

    buttons_board1.fill(1);
    buttons_board2.fill(0);

    bh1 = new button_harmony(1);
    bh2 = new button_harmony(0);

    background = new sf::RectangleShape({ 1080.f, 1080.f });
    background->setOrigin({ 540.f,540.f });
    background->setPosition(540.f, 500.f);

	counter1 = 0;
	counter2 = 0;
	player = 1;
	moved = 0;
	cursor_position = { 0,0 };
	chosen_tile = nullptr;
}

Game::Game(sf::Texture* rug)
{
    border = 1080;
    window = nullptr;

    b.make_place();
    b.fill();

    //Zrób, ze zależą od <border>, jeśli chcesz różną wielkość okna
    background = new sf::RectangleShape({ 1080.f, 1080.f });
    background->setOrigin({ 540.f,540.f });
    background->setPosition(540.f, 540.f);
    background->setTexture(rug);

    buttons_board1.fill(1);
    buttons_board2.fill(0);

    bh1 = new button_harmony(1);
    bh2 = new button_harmony(0);

    counter1 = 0;
    counter2 = 0;
    player = 1;
    moved = 0;
    cursor_position = { 0,0 };
    chosen_tile = nullptr;

    background->setOrigin({ 540.f,540.f });
}

void Game::switch_player()
{
	if (player == 0)
		player = 1;
	else
		player = 0;

    //palenie cierni
    int row = 0;
    int column = 0;
    for (auto it : b.get_tab())
    {
        for (auto it1 : it)
        {
            if (it1->get_tile() != nullptr and it1->get_tile()->get_type() == 4)
            {
                if (b.thorned(row, column))
                {
                    if (row + 1 <= 32 and row + 1 >= 0 and column <= 15 and column >= 0)
                    {
                        if (b.get_tab()[row + 1][column]->get_tile() != nullptr)
                        {
                            if (b.get_tab()[row + 1][column]->get_tile()->get_type() == 5)
                            {
                                b.get_tab()[row + 1][column]->assign_tile(nullptr);
                            }
                        }
                    }
                    if (row + 1 <= 32 and row + 1 >= 0 and column - 1 <= 15 and column - 1 >= 0)
                    {
                        if (b.get_tab()[row + 1][column - 1]->get_tile() != nullptr)
                        {
                            if (b.get_tab()[row + 1][column - 1]->get_tile()->get_type() == 5)
                            {
                                b.get_tab()[row + 1][column-1]->assign_tile(nullptr);
                            }
                        }
                    }
                    if (row - 1 <= 32 and row - 1 >= 0 and column <= 15 and column >= 0)
                    {
                        if (b.get_tab()[row - 1][column]->get_tile() != nullptr)
                        {
                            if (b.get_tab()[row - 1][column]->get_tile()->get_type() == 5)
                            {
                                b.get_tab()[row - 1][column]->assign_tile(nullptr);
                            }
                        }
                    }
                    if (row - 1 <= 32 and row - 1 >= 0 and column - 1 <= 15 and column - 1 >= 0)
                    {
                        if (b.get_tab()[row - 1][column - 1]->get_tile() != nullptr)
                        {
                            if (b.get_tab()[row - 1][column - 1]->get_tile()->get_type() == 5)
                            {
                                b.get_tab()[row - 1][column - 1]->assign_tile(nullptr);
                            }
                        }
                    }
                    else
                    {
                        //return 0;
                    }
                }
            }
            ++column;
        }
        ++row;
        column = 0;
    }
}

bool Game::play(sf::Vector2<std::string>* names)
{
    bool out = 0;
    bool blinker = 0;
    int button_counter = 0;
    bool harmony = 0;
    bool harmony1 = 0;
    tile* tile1 = nullptr;
    window = new sf::RenderWindow(sf::VideoMode(border, border), "Pai sho", sf::Style::Close);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/Gabriola.ttf");

    sf::Text text1;
    text1.setFillColor(sf::Color::Black);
    text1.setFont(font);
    text1.setCharacterSize(40);
    text1.setPosition({ 865, 35 });
    text1.setStyle(sf::Text::Bold);
    if (!names->x.empty())
        text1.setString(names->x);

    sf::Text text2;
    text2.setFillColor(sf::Color::White);
    text2.setFont(font);
    text2.setCharacterSize(40);
    text2.setPosition({ 38, 895 });
    text2.setStyle(sf::Text::Bold);
    if (!names->y.empty())
        text2.setString(names->y);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window->close();
                return 0;
            }

            if (player == 1 and (!harmony and !harmony1))
            {
                bh1->get_rectangle()->setOutlineColor(sf::Color::Green);
                bh2->reset();
            }
            if (player == 0 and (!harmony and !harmony1))
            {
                bh2->get_rectangle ()->setOutlineColor(sf::Color::Green);
                bh1->reset();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (harmony == 1 or harmony1 == 1)
                {
                    window->close();
                    return 1;
                }
                bh1->reset();
                bh2->reset();
                cursor_position = sf::Mouse::getPosition(*window);

                //walnięcie guziora
                if (!b.check_position(cursor_position))
                {
                    if (counter1 == 0)
                    {
                        if (player == 1)
                        {
                            if (bh1->borderx > cursor_position.x and bh1->border_x < cursor_position.x and bh1->bordery > cursor_position.y and bh1->border_y < cursor_position.y)
                            {
                                if (bh1->harmonise(&b))
                                {
                                    harmony = 1;
                                }
                                else
                                {
                                    switch_player();
                                }
                            }
                            else
                            {
                                for (auto guzior : buttons_board1.get_buttons())
                                {
                                    if (guzior != nullptr)
                                    {
                                        if (guzior->borderx > cursor_position.x and guzior->border_x < cursor_position.x and guzior->bordery > cursor_position.y and guzior->border_y < cursor_position.y)
                                        {
                                            tile1 = guzior->trigger(b);
                                            
                                            if (tile1 != nullptr)
                                            {
                                                if (tile1->get_type() != 5 and tile1->get_type() != 6)
                                                {
                                                    button_counter = 0;
                                                    switch_player();
                                                    break;
                                                }
                                                else
                                                {
                                                    if (buttons_board1.get_buttons()[button_counter]->draw == 1)
                                                    {
                                                        b.show_moves(tile1->get_type());
                                                        counter2 = 2;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        ++button_counter;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (bh2->borderx > cursor_position.x and bh2->border_x < cursor_position.x and bh2->bordery > cursor_position.y and bh2->border_y < cursor_position.y)
                            {
                                if (bh2->harmonise(&b))
                                {
                                    harmony1 = 1;
                                }
                                else
                                {
                                    switch_player();
                                }
                            }
                            else
                            {
                                for (auto guzior : buttons_board2.get_buttons())
                                {
                                    if (guzior != nullptr)
                                    {
                                        if (guzior->borderx > cursor_position.x and guzior->border_x < cursor_position.x and guzior->bordery > cursor_position.y and guzior->border_y < cursor_position.y)
                                        {
                                            tile1 = guzior->trigger(b);
                                            if (tile1 != nullptr)
                                            {
                                                if (tile1->get_type() != 5 and tile1->get_type() != 6)
                                                {
                                                    button_counter = 0;
                                                    switch_player();
                                                    break;
                                                }
                                                else
                                                {
                                                    if (buttons_board2.get_buttons()[button_counter]->draw == 1)
                                                    {
                                                        b.show_moves(tile1->get_type());
                                                        counter2 = 2;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        ++button_counter;
                                    }
                                }
                            }
                        }
                    }
                   
                }

                //ruch pionka
                else
                {
                    if (counter1 == 2)
                    {
                        moved = b.move_tile(cursor_position, tile1);
                        b.hide_moves();
                        counter2 = 0;
                        if (moved)
                        {
                            if (player == 1)
                            {
                                buttons_board1.remove(button_counter);
                                button_counter = 0;
                            }
                            if (player == 0)
                            {
                                buttons_board2.remove(button_counter);
                                button_counter = 0;
                            }
                            switch_player();
                        }
                    }
                    button_counter = 0;

                    if (counter1 == 0)
                    {
                        chosen_tile = b.find_tile(cursor_position);

                        if (chosen_tile->row != 0 or chosen_tile->column != 0)
                        {
                            if (chosen_tile->place1->get_tile()->player == player)
                            {
                                chosen_tile = b.find_tile(cursor_position);
                                b.show_moves(chosen_tile);
                                counter2 = 1;
                            }
                        }
                    }
                    if (counter1 == 1)
                    {
                        moved = b.move_tile(cursor_position, chosen_tile);
                        b.hide_moves();
                        counter2 = 0;

                        if (moved)
                            switch_player();
                    }
                }
                counter1 = counter2;
            }

        }
        window->clear();
        window->draw(*background);
        window->draw(b.get_circle());
        b.draw_tiles(window);

        for (auto guzior : buttons_board1.get_buttons())
        {
            if(guzior != nullptr and guzior->draw == 1)
                window->draw(*guzior->get_hitbox());
        }
        for (auto guzior : buttons_board2.get_buttons())
        {
            if (guzior != nullptr and guzior->draw == 1)
                window->draw(*guzior->get_hitbox());
        }
        window->draw(*bh1->get_rectangle());
        window->draw(*bh2->get_rectangle());
        window->draw(text2);
        window->draw(text1);
        window->display();

        if (harmony == 1 or harmony1 == 1)
        {
            std::thread mig(wait, 500);
            mig.join();

            for (auto it : b.get_tab())
            {
                for (auto it1 : it)
                {
                    if (it1->get_tile() != nullptr and it1->get_tile()->victorious)
                    {
                        if (blinker == 0)
                        {
                            it1->get_tile()->unmark();
                        }
                        else
                        {
                            it1->get_tile()->mark2();
                        }
                    }
                }
            }
            if (harmony == 1)
            {
                if (blinker == 1)
                    bh1->get_rectangle()->setOutlineColor(sf::Color::Magenta);
                else
                    bh1->reset();
            }
            if (harmony1 == 1)
            {
                if (blinker == 1)
                    bh2->get_rectangle()->setOutlineColor(sf::Color::Magenta);
                else
                    bh2->reset();
            }

            if (blinker == 0)
                blinker = 1;
            else
                blinker = 0;

        }
    }
}