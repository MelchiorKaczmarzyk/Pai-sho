#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/system.hpp>
#include <iostream>
#include <random>
#include <fstream>
#include <filesystem>
#include "Game.h"
#include "menu.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    //Losowanie tekstury tła
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);
    int counter = dist(rng);

    std::string folder_name = "texture_rugs";
    fs::path pth(fs::current_path()/folder_name);
    std::string texture_path;

    for (auto& p : fs::directory_iterator(pth))
    {
        if (counter == 0)
        {
            texture_path = p.path().string();
            break;
        }
        --counter;
    }

    sf::Texture* texture_rug = new sf::Texture;
    texture_rug->loadFromFile(texture_path);
    texture_rug->setSmooth(1);

    //Uruchomienie gry
    Game* game = new Game(texture_rug);
    menu* Menu = new menu;

    sf::Vector2<std::string>* Names;
    bool keep_playing = 1;
    while (keep_playing)
    {
        Names = Menu->activate();
        if (Names->x.empty() and Names->y.empty())
        {
            break;
        }
        else
        {
            keep_playing = game->play(Names);
            if (!keep_playing)
            {
                break;
            }
        }
        game = new Game(texture_rug);
        Menu = new menu;
    }
    return 0;
}
