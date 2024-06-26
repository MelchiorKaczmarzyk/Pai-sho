#include <iostream>
#include <filesystem>
#include "board.h"
#include "tile_air.h"
#include "tile_earth.h"
#include "tile_fire.h"
#include "tile_water.h"
#include "tile_lotus.h"

using namespace std;

board::board()
{
	center = { 540,500 };
	unit = 52.f;
	circle.setRadius(468);
	circle.setPointCount(300);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setOutlineThickness(17);
	circle.setOutlineColor(sf::Color::White);

	sf::Texture* texture_board = new sf::Texture;
	texture_board->loadFromFile("texture1.png");
	circle.setTexture(texture_board);

	float border = 1080;
	circle.setPosition(border / 2, border / 2 - 40);
}
board::~board()
{

}

sf::CircleShape board::get_circle()
{
	return circle;
}

std::vector<std::vector<place*>> board::get_tab()
{
	return tab;
}

bool board::harmony(bool player1)
{
	std::vector<tile*> v;
	tile* tile1 = nullptr;
	tile* tile2 = nullptr;
	tile* tile3 = nullptr;
	tile* tile_boulder1 = nullptr;
	tile* tile_boulder2 = nullptr;
	bool harmony1 = 0;
	bool harmony2 = 0;
	bool harmony3 = 0;
	bool harmony4 = 0;
	bool the_harmony = 0;
	int counter = 1;

	for (int i = 0; i < 16; i += 2)
	{
		if (harmony1 == 1)
			break;
		tile3 = tab[i][8]->get_tile();

		for (int j = 7; j >= 0; --j)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		for (int j = 9; j <= 16; ++j)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}
		
		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony1 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony1 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony1 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony1 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony1 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony1 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		v.clear();
		return 0;
	}
	
	//harmonia 2
	for (int i = 18; i <= 32; i += 2)
	{
		if (harmony2 == 1)
			break;
		tile3 = tab[i][8]->get_tile();

		for (int j = 7; j >= 0; --j)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		for (int j = 9; j <= 16; ++j)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony2 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony2 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony2 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony2 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony2 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony2 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		v.clear();
		return 0;
	}

	//harmonia 3
	for (int j = 0; j < 8; ++j)
	{
		if (harmony3 == 1)
			break;
		tile3 = tab[16][j]->get_tile();

		for (int i = 16; i >= 0; i -= 2)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}
		for (int i = 18; i <= 32; i += 2)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony3 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony3 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony3 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony3 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony3 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony3 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		return 0;
		v.clear();
	}
	
	//harmonia 4
	for (int j = 9; j <= 16; ++j)
	{
		if (harmony4 == 1)
			break;

		tile3 = tab[16][j]->get_tile();

		for (int i = 16; i >= 0; i -= 2)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		for (int i = 18; i <= 32; i += 2)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony4 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony4 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony4 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony4 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony4 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony4 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		v.clear();
		return 0;
	}

	//zakończenie
	for (auto it : v)
	{
		it->deharmonise();
		it->unmark();
	}

	if (harmony1 and harmony2 and harmony3 and harmony4)
		the_harmony = 1;

	if (the_harmony)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->victorious = 1;
			it->mark2();
		}
		v.clear();
		return 1;
	}
	else
		return 0;
}
bool board::harmony2(bool player1)
{
	std::vector<tile*> v;
	tile* tile1 = nullptr;
	tile* tile2 = nullptr;
	tile* tile3 = nullptr;
	tile* tile_boulder1 = nullptr;
	tile* tile_boulder2 = nullptr;
	bool harmony1 = 0;
	bool harmony2 = 0;
	bool harmony3 = 0;
	bool harmony4 = 0;
	bool the_harmony = 0;
	int counter = 1;

	//harmonia 3'''
	for (int j = 0; j < 8; ++j)
	{
		if (harmony3 == 1)
			break;
		tile3 = tab[16][j]->get_tile();

		for (int i = 16; i >= 0; i -= 2)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}
		for (int i = 18; i <= 32; i += 2)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony3 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony3 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony3 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony3 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony3 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony3 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		v.clear();
		return 0;
	}

	//harmonia 4'''
	for (int j = 9; j <= 16; ++j)
	{
		if (harmony4 == 1)
			break;

		tile3 = tab[16][j]->get_tile();

		for (int i = 16; i >= 0; i -= 2)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		for (int i = 18; i <= 32; i += 2)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony4 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony4 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony4 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony4 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony4 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony4 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		v.clear();
		return 0;
	}

	//harmonia 1'''
	for (int i = 0; i <= 16; i += 2)
	{
		if (harmony1 == 1)
			break;
		tile3 = tab[i][8]->get_tile();

		for (int j = 7; j >= 0; --j)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		for (int j = 9; j <= 16; ++j)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony1 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony1 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony1 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony1 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony1 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony1 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
		}
		v.clear();
		return 0;
	}


	//harmonia 2'''
	for (int i = 18; i <= 32; i += 2)
	{
		if (harmony2 == 1)
			break;
		tile3 = tab[i][8]->get_tile();

		for (int j = 7; j >= 0; --j)
		{
			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder1 = tab[i][j]->get_tile();
				}
				else
				{
					tile1 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}

		for (int j = 9; j <= 16; ++j)
		{

			if (tab[i][j]->get_tile() != nullptr and tab[i][j]->get_tile()->harmonised == 0)
			{
				if (tab[i][j]->get_tile()->get_type() == 6)
				{
					tile_boulder2 = tab[i][j]->get_tile();
				}
				else
				{
					tile2 = tab[i][j]->get_tile();
					break;
				}
			}
			++counter;
		}


		if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and tile1->player == player1 and tile2->player == player1 and tile1->harmonised != 1 and tile2->harmonised != 1)
		{
			tile1->harmonise();
			tile2->harmonise();
			v.push_back(tile1);
			v.push_back(tile2);
			harmony2 = 1;
		}
		else
		{
			if (tile1 != nullptr and tile2 != nullptr and tile_boulder1 == nullptr and tile_boulder2 == nullptr and tile3 == nullptr and ((tile1->get_type() == 0 and tile2->get_type() == 0) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and tile1->harmonised != 1 and tile2->harmonised != 1)
			{
				tile1->harmonise();
				tile2->harmonise();
				v.push_back(tile1);
				v.push_back(tile2);
				harmony2 = 1;
			}
			else
			{
				if (tile1 != nullptr and tile2 != nullptr and ((tile1->player == player1 and tile2->player == player1) or (tile1->player == player1 and tile2->get_type() == 0) or (tile2->player == player1 and tile1->get_type() == 0)) and (tile3 == nullptr or tile3->get_type() == 6) and (tile1->get_type() == 3 or tile2->get_type() == 3) and tile1->harmonised != 1 and tile2->harmonised != 1)
				{
					tile1->harmonise();
					tile2->harmonise();
					v.push_back(tile1);
					v.push_back(tile2);
					harmony2 = 1;
				}
				else
				{
					if (tile2 != nullptr and tile2->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder1 != nullptr and tile2->get_type() == 3)
					{
						tile_boulder1->harmonise();
						tile2->harmonise();
						v.push_back(tile_boulder1);
						v.push_back(tile2);
						harmony2 = 1;
					}
					else
					{
						if (tile1 != nullptr and tile1->player == player1 and (tile3 == nullptr or tile3->get_type() == 6) and tile_boulder2 != nullptr and tile1->get_type() == 3)
						{
							tile_boulder2->harmonise();
							tile1->harmonise();
							v.push_back(tile1);
							v.push_back(tile_boulder2);
							harmony2 = 1;
						}
					}
				}
			}
		}
		counter = 1;
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile_boulder1 = nullptr;
		tile_boulder2 = nullptr;
	}

	if (harmony2 == 0)
	{
		for (auto it : v)
		{
			it->deharmonise();
			it->unmark();
		}
		v.clear();
		return 0;
	}

	//zakończenie
	for (auto it : v)
	{
		it->deharmonise();
		it->unmark();
	}

	if (harmony1 and harmony2 and harmony3 and harmony4)
		the_harmony = 1;

	if (the_harmony)
	{
		for (auto it : v)
		{
			it->victorious = 1;
			it->deharmonise();
			it->mark2();
		}
		v.clear();
		return 1;
	}
	else
		return 0;
}

bool board::thorned(int row, int column)
{
	if (row + 1 <= 32 and row + 1 >= 0 and column <= 15 and column >= 0)
	{
		if (tab[row + 1][column]->get_tile() != nullptr)
		{
			if (tab[row + 1][column]->get_tile()->get_type() == 5)
			{
				return 1;
			}
		}
	}
	if (row + 1 <= 32 and row + 1 >= 0 and column - 1 <= 15 and column - 1 >= 0)
	{
		if (tab[row + 1][column - 1]->get_tile() != nullptr)
		{
			if (tab[row + 1][column - 1]->get_tile()->get_type() == 5)
			{
				return 1;
			}
		}
	}
	if (row - 1 <= 32 and row - 1 >= 0 and column <= 15 and column >= 0)
	{
		if (tab[row - 1][column]->get_tile() != nullptr)
		{
			if (tab[row - 1][column]->get_tile()->get_type() == 5)
			{
				return 1;
			}
		}
	}
	if (row - 1 <= 32 and row - 1 >= 0 and column - 1 <= 15 and column - 1 >= 0)
	{
		if (tab[row - 1][column - 1]->get_tile() != nullptr)
		{
			if (tab[row - 1][column - 1]->get_tile()->get_type() == 5)
			{
				return 1;
			}
		}
	}
	else
	{
		return 0;
	}
}

place_index* board::find_tile(sf::Vector2i v)
{
	int counter_row = 0;
	int counter_column = 0;
	sf::Vector2f v1 = { static_cast<float>(v.x), static_cast<float>(v.y) };
	for (auto it : tab)
	{
		for (auto it1 : it)
		{
			if (it1->get_tile() != nullptr)
			{
				if (it1->get_tile()->borderx >= v1.x and it1->get_tile()->border_x <= v1.x and it1->get_tile()->bordery >= v1.y and it1->get_tile()->border_y <= v1.y)
				{
					return new place_index{ counter_row, counter_column, it1 };
				}
			}
			++counter_column;
		}
		counter_column = 0;
		++counter_row;
	}
	return new place_index{ 0, 0, nullptr };
}

bool board::move_tile(sf::Vector2i v, place_index* pi)
{
	sf::Vector2f v1 = { static_cast<float>(v.x), static_cast<float>(v.y) };
	int counter_row = 0;
	int counter_column = 0;

	for (auto it : tab)
	{
		for (auto it1 : it)
		{
			if (it1->borderx >= v1.x and it1->border_x <= v1.x and it1->bordery >= v1.y and it1->border_y <= v1.y)
			{
				if (counter_row == pi->row and counter_column == pi->column)
				{
					return 0;
				}
				else
				{
					tab[pi->row][pi->column]->get_tile()->already_moved = 1;
					if (tab[counter_row][counter_column]->is_drawn())
					{
						tab[pi->row][pi->column]->get_tile()->put(tab[counter_row][counter_column]->get_position());

						tab[counter_row][counter_column]->assign_tile(pi->place1->get_tile());
						tab[pi->row][pi->column]->assign_tile(nullptr);
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
			++counter_column;
		}
		counter_column = 0;
		++counter_row;
	}
}
bool board::move_tile(sf::Vector2i v, tile* tile1)
{
	sf::Vector2f v1 = { static_cast<float>(v.x), static_cast<float>(v.y) };
	int counter_row = 0;
	int counter_column = 0;

	for (auto it : tab)
	{
		for (auto it1 : it)
		{
			if (it1->borderx >= v1.x and it1->border_x <= v1.x and it1->bordery >= v1.y and it1->border_y <= v1.y)
			{
				if (tab[counter_row][counter_column]->is_drawn())
				{
					tile1->put(tab[counter_row][counter_column]->get_position());
					tab[counter_row][counter_column]->assign_tile(tile1);
					return 1;
				}
			}
			++counter_column;
		}
		++counter_row;
		counter_column = 0;
	}
	return 0;
}

void board::show_moves(place_index* pi)
{
	bool blocked = 0;
	int counter_row = 0;
	int counter_column = 0;
	int wiersz = pi->row;
	int kolumna = pi->column;
	bool gracz = pi->place1->get_tile()->player;
	//boulder
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 6)
	{
		if (tab[pi->row][pi->column]->get_tile()->already_moved == 0)
		{
			for (auto it : tab)
			{
				for (auto it1 : it)
				{
					if (counter_row % 2 == 0)
					{
						if (it1->get_tile() == nullptr)
							it1->set_drawn(1);
					}
				}
				++counter_row;
			}
		}
		tab[2][8]->set_drawn(0);
		tab[30][8]->set_drawn(0);
	}
	//thorn
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 5)
	{
		if (tab[pi->row][pi->column]->get_tile()->already_moved == 0)
		{
			for (auto it : tab)
			{
				for (auto it1 : it)
				{
					if (counter_row % 2 == 1)
					{
						if (it1 == nullptr)
						{
							it1->set_drawn(1);
						}
					}
				}
				++counter_row;
			}
		}
	}
	//fire
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 4)
	{
		for (int i = 0; i <= 6; i += 2)
		{
			wiersz = pi->row + i;
			kolumna = pi->column;
			if (wiersz <= 32 and wiersz >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					//zapobieganie przeskakiwaniu przez nielegalne pola
					if (tab[wiersz][kolumna]->get_region() == 2)
					{
						blocked = 1;
					}

					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{
						blocked = 1;
						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
					}
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -6; i -= 2)
		{
			wiersz = pi->row + i;
			kolumna = pi->column;
			if (wiersz <= 32 and wiersz >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					//zapobieganie przeskakiwaniu przez nielegalne pola
					if (tab[wiersz][kolumna]->get_region() == 2)
					{
						blocked = 1;
					}

					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}

					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{
						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		for (int i = 0; i <= 3; ++i)
		{
			wiersz = pi->row;
			kolumna = pi->column + i;
			if (kolumna <= 16 and kolumna >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					//zapobieganie przeskakiwaniu przez nielegalne pola
					if (tab[wiersz][kolumna]->get_region() == 2)
					{
						blocked = 1;
					}

					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{
						
						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -3; --i)
		{
			wiersz = pi->row;
			kolumna = pi->column + i;
			if (kolumna <= 16 and kolumna >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					//zapobieganie przeskakiwaniu przez nielegalne pola
					if (tab[wiersz][kolumna]->get_region() == 2)
					{
						blocked = 1;
					}

					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{

						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		if (tab[pi->row][pi->column]->move_type == 3)
		{
			for (int i = 0; i <= 3; ++i)
			{
				wiersz = pi->row + (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >=0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -3; --i)
			{
				wiersz = pi->row + (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i <= 3; ++i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -3; --i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
		}
		if (tab[pi->row][pi->column]->move_type == 2)
		{
			for (int i = 0; i <= 3; ++i)
			{
				wiersz = pi->row + (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -3; --i)
			{
				wiersz = pi->row + (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
		}

		if (tab[pi->row][pi->column]->move_type == 1)
		{
			for (int i = 0; i <= 3; ++i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -3; --i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 2)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}
						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
		}
	}
	//earth
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 3)
	{
		//obsługa cierni 1
		if (this->thorned(wiersz, kolumna) != 1)
		{
			for (int i = 0; i <= 6; i += 2)
			{
				wiersz = pi->row + i;
				kolumna = pi->column;
				if (wiersz <= 32 and wiersz >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -6; i -= 2)
			{
				wiersz = pi->row + i;
				kolumna = pi->column;
				if (wiersz <= 32 and wiersz >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i <= 3; ++i)
			{
				wiersz = pi->row;
				kolumna = pi->column + i;
				if (kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -3; --i)
			{
				wiersz = pi->row;
				kolumna = pi->column + i;
				if (kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						//zapobieganie przeskakiwaniu przez nielegalne pola
						if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
						{
							blocked = 1;
						}

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			if (tab[pi->row][pi->column]->move_type == 3)
			{
				for (int i = 0; i <= 3; ++i)
				{
					wiersz = pi->row + (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
				for (int i = 0; i >= -3; --i)
				{
					wiersz = pi->row + (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
				for (int i = 0; i <= 3; ++i)
				{
					wiersz = pi->row - (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
				for (int i = 0; i >= -3; --i)
				{
					wiersz = pi->row - (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 2)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
			}
			if (tab[pi->row][pi->column]->move_type == 2)
			{
				for (int i = 0; i <= 3; ++i)
				{
					wiersz = pi->row + (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
				for (int i = 0; i >= -3; --i)
				{
					wiersz = pi->row + (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
			}

			if (tab[pi->row][pi->column]->move_type == 1)
			{
				for (int i = 0; i <= 3; ++i)
				{
					wiersz = pi->row - (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;

							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
				for (int i = 0; i >= -3; --i)
				{
					wiersz = pi->row - (2 * i);
					kolumna = pi->column + i;
					if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
					{
						if (tab[wiersz][kolumna]->get_region() != 0)
						{
							//zapobieganie przeskakiwaniu przez nielegalne pola
							if (tab[wiersz][kolumna]->get_region() == 3 or tab[wiersz][kolumna]->get_region() == 13)
							{
								blocked = 1;
							}

							if (!blocked)
							{
								if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->set_drawn(1);
							}

							//obsługa cierni 2
							if (this->thorned(wiersz, kolumna) == 1)
								blocked = 1;
								
							if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
							{

								if (tab[wiersz][kolumna]->get_tile()->player != gracz)
								{
									if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
									{
										if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 23 or tab[wiersz][kolumna]->get_region() == 123)
											tab[wiersz][kolumna]->get_tile()->mark();
									}
									else
										tab[wiersz][kolumna]->set_drawn(0);
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
								blocked = 1;
							}
						}
					}
				}
				blocked = 0;
			}
		}
	}
	//water
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 2)
	{
		for (int i = 0; i <= 4; i += 2)
		{
			wiersz = pi->row + i;
			kolumna = pi->column;
			if (wiersz <= 32 and wiersz >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}

					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{

						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -4; i -= 2)
		{
			wiersz = pi->row + i;
			kolumna = pi->column;
			if (wiersz <= 32 and wiersz >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}

					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{

						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (blocked != 1 and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		for (int i = 0; i <= 2; ++i)
		{
			wiersz = pi->row;
			kolumna = pi->column + i;
			if (kolumna <= 16 and kolumna >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
			
					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}

					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{

						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -2; --i)
		{
			wiersz = pi->row;
			kolumna = pi->column + i;
			if (kolumna <= 16 and kolumna >= 0)
			{
				if (tab[wiersz][kolumna]->get_region() != 0)
				{
					if (!blocked)
					{
						if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
							tab[wiersz][kolumna]->set_drawn(1);
					}

					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;

					if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
					{

						if (tab[wiersz][kolumna]->get_tile()->player != gracz)
						{
							if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
							{
								if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
									tab[wiersz][kolumna]->get_tile()->mark();
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
						}
						else
							tab[wiersz][kolumna]->set_drawn(0);
						blocked = 1;
					}
				}
			}
		}
		blocked = 0;
		if (tab[pi->row][pi->column]->move_type == 3)
		{
			for (int i = 0; i <= 2; ++i)
			{
				wiersz = pi->row + (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -2; --i)
			{
				wiersz = pi->row + (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{

						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i <= 2; ++i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -2; --i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
		}
		if (tab[pi->row][pi->column]->move_type == 1)
		{
			for (int i = 0; i <= 2; ++i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 1 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
			for (int i = 0; i >= -2; --i)
			{
				wiersz = pi->row - (2 * i);
				kolumna = pi->column + i;
				if (wiersz <= 32 and wiersz >= 0 and kolumna <= 16 and kolumna >= 0)
				{
					if (tab[wiersz][kolumna]->get_region() != 0)
					{
						if (!blocked)
						{
							if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
								tab[wiersz][kolumna]->set_drawn(1);
						}

						//obsługa cierni 2
						if (this->thorned(wiersz, kolumna) == 1)
							blocked = 1;

						if (i != 0 and (tab[wiersz][kolumna]->get_tile() != nullptr))
						{

							if (tab[wiersz][kolumna]->get_tile()->player != gracz)
							{
								if (!blocked and tab[wiersz][kolumna]->get_tile()->get_type() == 2 or tab[wiersz][kolumna]->get_tile()->get_type() == 3 or tab[wiersz][kolumna]->get_tile()->get_type() == 4)
								{
									if (tab[wiersz][kolumna]->get_region() == 2 or tab[wiersz][kolumna]->get_region() == 12 or tab[wiersz][kolumna]->get_region() == 13 or tab[wiersz][kolumna]->get_region() == 123)
										tab[wiersz][kolumna]->get_tile()->mark();
								}
								else
									tab[wiersz][kolumna]->set_drawn(0);
							}
							else
								tab[wiersz][kolumna]->set_drawn(0);
							blocked = 1;
						}
					}
				}
			}
			blocked = 0;
		}
	}
	//air
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 1)
	{
		for (int i = 0; i <= 8; i += 2)
		{
			wiersz = pi->row + i;
			kolumna = pi->column;
			if (pi->row + i <= 32 and pi->row + i >= 0)
			{
				if (tab[pi->row + i][pi->column]->get_region() != 0)
				{
					if (i != 0 and (tab[pi->row + i][pi->column]->get_tile() != nullptr))
						blocked = 1;

					if (!blocked)
					{
						tab[pi->row + i][pi->column]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -8; i -= 2)
		{
			wiersz = pi->row + i;
			kolumna = pi->column;
			if (pi->row + i <= 32 and pi->row + i >= 0)
			{
				if (tab[pi->row + i][pi->column]->get_region() != 0)
				{
					if (i != 0 and (tab[pi->row + i][pi->column]->get_tile() != nullptr))
						blocked = 1;

					if (!blocked)
					{
						tab[pi->row + i][pi->column]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i <= 4; ++i)
		{
			wiersz = pi->row;
			kolumna = pi->column + i;
			if (pi->column + i <= 16 and pi->column + i >= 0)
			{
				if (tab[pi->row][pi->column + i]->get_region() != 0)
				{
					if (i != 0 and tab[pi->row][pi->column + i]->get_tile() != nullptr)
						blocked = 1;

					if (!blocked)
					{
						tab[pi->row][pi->column + i]->set_drawn(1);
					}

					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -4; --i)
		{
			wiersz = pi->row;
			kolumna = pi->column + i;

			if (pi->column + i <= 16 and pi->column + i >= 0)
			{
				if (tab[pi->row][pi->column + i]->get_region() != 0)
				{
					if (i != 0 and tab[pi->row][pi->column + i]->get_tile() != nullptr)
						blocked = 1;

					if (!blocked)
					{
						tab[pi->row][pi->column + i]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i <= 2; ++i)
		{
			wiersz = pi->row + (2 * i);
			kolumna = pi->column + i;
			if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row + (2 * i) <= 32 and pi->row + (2 * i) >= 0)
			{
				if (tab[pi->row + (2 * i)][pi->column + i]->get_region() != 0)
				{
					if (i != 0 and (tab[pi->row + (2 * i)][pi->column + i]->get_tile() != nullptr))
						blocked = 1;

					if (!blocked)
					{
							tab[pi->row + (2 * i)][pi->column + i]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -2; --i)
		{
			wiersz = pi->row + (2 * i);
			kolumna = pi->column + i;
			if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row + (2 * i) <= 32 and pi->row + (2 * i) >= 0)
			{
				if (tab[pi->row + (2 * i)][pi->column + i]->get_region() != 0)
				{
					if (i != 0 and (tab[pi->row + (2 * i)][pi->column + i]->get_tile() != nullptr))
						blocked = 1;

					if (!blocked)
					{
							tab[pi->row + (2 * i)][pi->column + i]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i <= 2; ++i)
		{
			wiersz = pi->row - (2 * i);
			kolumna = pi->column + i;
			if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row - (2 * i) <= 32 and pi->row - (2 * i) >= 0)
			{
				if (tab[pi->row - (2 * i)][pi->column + i]->get_region() != 0)
				{
					if (i != 0 and (tab[pi->row - (2 * i)][pi->column + i]->get_tile() != nullptr))
						blocked = 1;

					if (!blocked)
					{
							tab[pi->row - (2 * i)][pi->column + i]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
		for (int i = 0; i >= -2; --i)
		{
			wiersz = pi->row - (2 * i);
			kolumna = pi->column + i;
			if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row - (2 * i) <= 32 and pi->row - (2 * i) >= 0)
			{
				if (tab[pi->row - (2 * i)][pi->column + i]->get_region() != 0)
				{
					if (i != 0 and (tab[pi->row - (2 * i)][pi->column + i]->get_tile() != nullptr))
						blocked = 1;

					if (!blocked)
					{
							tab[pi->row - (2 * i)][pi->column + i]->set_drawn(1);
					}
					//obsługa cierni 2
					if (this->thorned(wiersz, kolumna) == 1)
						blocked = 1;
				}
			}
		}
		blocked = 0;
	}
	//lotus
	if (tab[pi->row][pi->column]->get_tile()->get_type() == 0)
	{
		for (int i = 10; i >= -10; i -= 2)
		{
			if (pi->row + i <= 32 and pi->row + i >= 0)
			{
				if (tab[pi->row + i][pi->column]->get_region() != 0)
				{
					if (tab[pi->row + i][pi->column]->get_tile() == nullptr)
						tab[pi->row + i][pi->column]->set_drawn(1);
				}
			}
		}
		for (int i = 5; i >= -5; i -= 1)
		{
			if (pi->column + i <= 16 and pi->column + i >= 0)
			{
				if (tab[pi->row][pi->column + i]->get_region() != 0)
				{
					if (tab[pi->row][pi->column + i]->get_tile() == nullptr)
						tab[pi->row][pi->column + i]->set_drawn(1);
				}
			}
		}
		if (tab[pi->row][pi->column]->move_type == 3)
		{
			for (int i = 5; i >= -5; i -= 1)
			{
				if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row + (2 * i) <= 32 and pi->row + (2 * i) >= 0)
				{
					if (tab[pi->row + (2 * i)][pi->column + i]->get_region() != 0)
					{
						if (tab[pi->row + (2 * i)][pi->column + i]->get_tile() == nullptr)
							tab[pi->row + (2 * i)][pi->column + i]->set_drawn(1);
					}
				}
			}
			for (int i = 5; i >= -5; i -= 1)
			{
				if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row - (2 * i) <= 32 and pi->row - (2 * i) >= 0)
				{
					if (tab[pi->row - (2 * i)][pi->column + i]->get_region() != 0)
					{
						if (tab[pi->row - (2 * i)][pi->column + i]->get_tile() == nullptr)
							tab[pi->row - (2 * i)][pi->column + i]->set_drawn(1);
					}
				}
			}
		}
		if (tab[pi->row][pi->column]->move_type == 2)
		{
			for (int i = 5; i >= -5; i -= 1)
			{
				if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row + (2 * i) <= 32 and pi->row + (2 * i) >= 0)
				{
					if (tab[pi->row + (2 * i)][pi->column + i]->get_region() != 0)
					{
						if (tab[pi->row + (2 * i)][pi->column + i]->get_tile() == nullptr)
							tab[pi->row + (2 * i)][pi->column + i]->set_drawn(1);
					}
				}
			}
		}

		if (tab[pi->row][pi->column]->move_type == 1)
		{
			for (int i = 5; i >= -5; i -= 1)
			{
				if (pi->column + i <= 16 and pi->column + i >= 0 and pi->row - (2 * i) <= 32 and pi->row - (2 * i) >= 0)
				{
					if (tab[pi->row - (2 * i)][pi->column + i]->get_region() != 0)
					{
						if (tab[pi->row - (2 * i)][pi->column + i]->get_tile() == nullptr)
							tab[pi->row - (2 * i)][pi->column + i]->set_drawn(1);
					}
				}
			}
		}
	}
}
void board::show_moves(int type1)
{
	int counter_row = 0;
	if (type1 == 5)
	{
		for (auto it : tab)
		{
			for (auto it1 : it)
			{
				if (counter_row % 2 == 1)
				{
					if (it1->get_tile() == nullptr)
						it1->set_drawn(1);
				}
			}
			++counter_row;
		}
	}
	if (type1 == 6)
	{
		for (auto it : tab)
		{
			for (auto it1 : it)
			{
				if (counter_row % 2 == 0)
				{
					if (it1->get_tile() == nullptr)
						it1->set_drawn(1);
				}
			}
			++counter_row;
		}
		tab[2][8]->set_drawn(0);
		tab[30][8]->set_drawn(0);
	}
}

void board::hide_moves()
{
	int counter_row = 0;
	int counter_column = 0;
	for (auto it : tab)
	{
		for (auto it1 : it)
		{
			it1->set_drawn(0);
			if (it1->get_tile() != nullptr)
				it1->get_tile()->unmark();
		}
		++counter_column;
	}
	counter_column = 0;
	++counter_row;
}

bool board::check_position(sf::Vector2i v)
{
	sf::Vector2f v1 = { static_cast<float>(v.x), static_cast<float>(v.y) };
	for (auto it : tab)
	{
		for (auto it1 : it)
		{
			if (it1->borderx >= v1.x and it1->border_x <= v1.x and it1->bordery >= v1.y and it1->border_y <= v1.y)
			{
				return 1;
			}
		}
	}
	return 0;
}

void board::make_place()
{
	std::vector<place*> v;
	//row 0
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 3 * unit, center.y - 8 * unit }));
	v.push_back(new place(2, { center.x - 2 * unit, center.y - 8 * unit }));
	v.push_back(new place(23, { center.x - 1 * unit, center.y - 8 * unit }));
	v.push_back(new place(3, { center.x - 0 * unit, center.y - 8 * unit }));
	v.push_back(new place(1, 23, { center.x + 1 * unit, center.y - 8 * unit }));
	v.push_back(new place(2, { center.x + 2 * unit, center.y - 8 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y - 8 * unit }));
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 1 - thorns
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (7.5f * unit) }));
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 2
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 5 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x - 3 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x - 2 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x - 1 * unit, center.y - 7 * unit }));
	v.push_back(new place(123, { center.x - 0 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x + 1 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x + 2 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y - 7 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y - 7 * unit }));
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 3 - thorns
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (6.5f * unit) }));
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 4
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 6 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x - 3 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x - 2 * unit, center.y - 6 * unit }));
	v.push_back(new place(12, { center.x - 1 * unit, center.y - 6 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 6 * unit }));
	v.push_back(new place(23, { center.x + 1 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x + 2 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y - 6 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y - 6 * unit }));
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 5 - thorns
	v.push_back(new place);
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y - (5.5f * unit) }));
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 6
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 7 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x - 3 * unit, center.y - 5 * unit }));
	v.push_back(new place(12, { center.x - 2 * unit, center.y - 5 * unit }));
	v.push_back(new place(1, { center.x - 1 * unit, center.y - 5 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 5 * unit }));
	v.push_back(new place(3, { center.x + 1 * unit, center.y - 5 * unit }));
	v.push_back(new place(23, { center.x + 2 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y - 5 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y - 5 * unit }));
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 7 - thorns
	v.push_back(new place);
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y - (4.5f * unit) }));
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 8
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 7 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y - 4 * unit }));
	v.push_back(new place(12, { center.x - 3 * unit, center.y - 4 * unit }));
	v.push_back(new place(1, { center.x - 2 * unit, center.y - 4 * unit }));
	v.push_back(new place(1, { center.x - 1 * unit, center.y - 4 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 4 * unit }));
	v.push_back(new place(3, { center.x + 1 * unit, center.y - 4 * unit }));
	v.push_back(new place(3, { center.x + 2 * unit, center.y - 4 * unit }));
	v.push_back(new place(23, { center.x + 3 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y - 4 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y - 4 * unit }));
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 9 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y - (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y - (3.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 10
	v.push_back(new place(2, { center.x - 8 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x - 7 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y - 3 * unit }));
	v.push_back(new place(12, { center.x - 4 * unit, center.y - 3 * unit }));
	v.push_back(new place(1, { center.x - 3 * unit, center.y - 3 * unit }));
	v.push_back(new place(1, { center.x - 2 * unit, center.y - 3 * unit }));
	v.push_back(new place(1, { center.x - 1 * unit, center.y - 3 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 3 * unit }));
	v.push_back(new place(3, { center.x + 1 * unit, center.y - 3 * unit }));
	v.push_back(new place(3, { center.x + 2 * unit, center.y - 3 * unit }));
	v.push_back(new place(3, { center.x + 3 * unit, center.y - 3 * unit }));
	v.push_back(new place(23, { center.x + 4 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y - 3 * unit }));
	v.push_back(new place(2, { center.x + 8 * unit, center.y - 3 * unit }));
	tab.push_back(v);
	v.clear();
	//row 11 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y - (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y - (2.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 12
	v.push_back(new place(2, { center.x - 8 * unit, center.y - 2 * unit }));
	v.push_back(new place(2, { center.x - 7 * unit, center.y - 2 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y - 2 * unit }));
	v.push_back(new place(12, { center.x - 5 * unit, center.y - 2 * unit }));
	v.push_back(new place(1, { center.x - 4 * unit, center.y - 2 * unit }));
	v.push_back(new place(1, { center.x - 3 * unit, center.y - 2 * unit }));
	v.push_back(new place(1, { center.x - 2 * unit, center.y - 2 * unit }));
	v.push_back(new place(1, { center.x - 1 * unit, center.y - 2 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 2 * unit }));
	v.push_back(new place(3, { center.x + 1 * unit, center.y - 2 * unit }));
	v.push_back(new place(3, { center.x + 2 * unit, center.y - 2 * unit }));
	v.push_back(new place(3, { center.x + 3 * unit, center.y - 2 * unit }));
	v.push_back(new place(3, { center.x + 4 * unit, center.y - 2 * unit }));
	v.push_back(new place(23, { center.x + 5 * unit, center.y - 2 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y - 2 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y - 2 * unit }));
	v.push_back(new place(2, { center.x + 8 * unit, center.y - 2 * unit }));
	tab.push_back(v);
	v.clear();
	//row 13 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y - (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y - (1.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 14
	v.push_back(new place(23, { center.x - 8 * unit, center.y - 1 * unit }));
	v.push_back(new place(2, { center.x - 7 * unit, center.y - 1 * unit }));
	v.push_back(new place(12, { center.x - 6 * unit, center.y - 1 * unit }));
	v.push_back(new place(1, { center.x - 5 * unit, center.y - 1 * unit }));
	v.push_back(new place(1, { center.x - 4 * unit, center.y - 1 * unit }));
	v.push_back(new place(1, { center.x - 3 * unit, center.y - 1 * unit }));
	v.push_back(new place(1, { center.x - 2 * unit, center.y - 1 * unit }));
	v.push_back(new place(1, { center.x - 1 * unit, center.y - 1 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 1 * unit }));
	v.push_back(new place(3, { center.x + 1 * unit, center.y - 1 * unit }));
	v.push_back(new place(3, { center.x + 2 * unit, center.y - 1 * unit }));
	v.push_back(new place(3, { center.x + 3 * unit, center.y - 1 * unit }));
	v.push_back(new place(3, { center.x + 4 * unit, center.y - 1 * unit }));
	v.push_back(new place(3, { center.x + 5 * unit, center.y - 1 * unit }));
	v.push_back(new place(23, { center.x + 6 * unit, center.y - 1 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y - 1 * unit }));
	v.push_back(new place(1, 23, { center.x + 8 * unit, center.y - 1 * unit }));
	tab.push_back(v);
	v.clear();
	//row 15 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y - (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y - (0.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 16
	v.push_back(new place(3, { center.x - 8 * unit, center.y - 0 * unit }));
	v.push_back(new place(123, { center.x - 7 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 6 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 5 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 4 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 3 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 2 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 1 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x + 1 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x + 2 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x + 3 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x + 4 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x + 5 * unit, center.y - 0 * unit }));
	v.push_back(new place(13, { center.x + 6 * unit, center.y - 0 * unit }));
	v.push_back(new place(123, { center.x + 7 * unit, center.y - 0 * unit }));
	v.push_back(new place(3, { center.x + 8 * unit, center.y - 0 * unit }));
	tab.push_back(v);
	v.clear();
	//row 17 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y + (0.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y + (0.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 18
	v.push_back(new place(1, 23, { center.x - 8 * unit, center.y + 1 * unit }));
	v.push_back(new place(2, { center.x - 7 * unit, center.y + 1 * unit }));
	v.push_back(new place(23, { center.x - 6 * unit, center.y + 1 * unit }));
	v.push_back(new place(3, { center.x - 5 * unit, center.y + 1 * unit }));
	v.push_back(new place(3, { center.x - 4 * unit, center.y + 1 * unit }));
	v.push_back(new place(3, { center.x - 3 * unit, center.y + 1 * unit }));
	v.push_back(new place(3, { center.x - 2 * unit, center.y + 1 * unit }));
	v.push_back(new place(3, { center.x - 1 * unit, center.y + 1 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y + 1 * unit }));
	v.push_back(new place(1, { center.x + 1 * unit, center.y + 1 * unit }));
	v.push_back(new place(1, { center.x + 2 * unit, center.y + 1 * unit }));
	v.push_back(new place(1, { center.x + 3 * unit, center.y + 1 * unit }));
	v.push_back(new place(1, { center.x + 4 * unit, center.y + 1 * unit }));
	v.push_back(new place(1, { center.x + 5 * unit, center.y + 1 * unit }));
	v.push_back(new place(12, { center.x + 6 * unit, center.y + 1 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y + 1 * unit }));
	v.push_back(new place(23, { center.x + 8 * unit, center.y + 1 * unit }));
	tab.push_back(v);
	v.clear();
	//row 19 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y + (1.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y + (1.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 20
	v.push_back(new place(2, { center.x - 8 * unit, center.y + 2 * unit }));
	v.push_back(new place(2, { center.x - 7 * unit, center.y + 2 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y + 2 * unit }));
	v.push_back(new place(23, { center.x - 5 * unit, center.y + 2 * unit }));
	v.push_back(new place(3, { center.x - 4 * unit, center.y + 2 * unit }));
	v.push_back(new place(3, { center.x - 3 * unit, center.y + 2 * unit }));
	v.push_back(new place(3, { center.x - 2 * unit, center.y + 2 * unit }));
	v.push_back(new place(3, { center.x - 1 * unit, center.y + 2 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y + 2 * unit }));
	v.push_back(new place(1, { center.x + 1 * unit, center.y + 2 * unit }));
	v.push_back(new place(1, { center.x + 2 * unit, center.y + 2 * unit }));
	v.push_back(new place(1, { center.x + 3 * unit, center.y + 2 * unit }));
	v.push_back(new place(1, { center.x + 4 * unit, center.y + 2 * unit }));
	v.push_back(new place(12, { center.x + 5 * unit, center.y + 2 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y + 2 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y + 2 * unit }));
	v.push_back(new place(2, { center.x + 8 * unit, center.y + 2 * unit }));
	tab.push_back(v);
	v.clear();
	// row 21 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y + (2.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y + (2.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 22
	v.push_back(new place(2, { center.x - 8 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x - 7 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y + 3 * unit }));
	v.push_back(new place(23, { center.x - 4 * unit, center.y + 3 * unit }));
	v.push_back(new place(3, { center.x - 3 * unit, center.y + 3 * unit }));
	v.push_back(new place(3, { center.x - 2 * unit, center.y + 3 * unit }));
	v.push_back(new place(3, { center.x - 1 * unit, center.y + 3 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y + 3 * unit }));
	v.push_back(new place(1, { center.x + 1 * unit, center.y + 3 * unit }));
	v.push_back(new place(1, { center.x + 2 * unit, center.y + 3 * unit }));
	v.push_back(new place(1, { center.x + 3 * unit, center.y + 3 * unit }));
	v.push_back(new place(12, { center.x + 4 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y + 3 * unit }));
	v.push_back(new place(2, { center.x + 8 * unit, center.y + 3 * unit }));
	tab.push_back(v);
	v.clear();
	//row 23 - thorns
	v.push_back(new place(0, { center.x - 7.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y + (3.5f * unit) }));
	v.push_back(new place(0, { center.x + 7.5f * unit, center.y + (3.5f * unit) }));
	tab.push_back(v);
	v.clear();
	//row 24
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 7 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y + 4 * unit }));
	v.push_back(new place(23, { center.x - 3 * unit, center.y + 4 * unit }));
	v.push_back(new place(3, { center.x - 2 * unit, center.y + 4 * unit }));
	v.push_back(new place(3, { center.x - 1 * unit, center.y + 4 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y + 4 * unit }));
	v.push_back(new place(1, { center.x + 1 * unit, center.y + 4 * unit }));
	v.push_back(new place(1, { center.x + 2 * unit, center.y + 4 * unit }));
	v.push_back(new place(12, { center.x + 3 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y + 4 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y + 4 * unit }));
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 25 - thorns
	v.push_back(new place());
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y + (4.5f * unit) }));
	v.push_back(new place());
	tab.push_back(v);
	v.clear();
	//row 26
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 7 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x - 6 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x - 3 * unit, center.y + 5 * unit }));
	v.push_back(new place(23, { center.x - 2 * unit, center.y + 5 * unit }));
	v.push_back(new place(3, { center.x - 1 * unit, center.y + 5 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y + 5 * unit }));
	v.push_back(new place(1, { center.x + 1 * unit, center.y + 5 * unit }));
	v.push_back(new place(12, { center.x + 2 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y + 5 * unit }));
	v.push_back(new place(2, { center.x + 7 * unit, center.y + 5 * unit }));
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 27 - thorns
	v.push_back(new place());
	v.push_back(new place(0, { center.x - 6.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place(0, { center.x + 6.5f * unit, center.y + (5.5f * unit) }));
	v.push_back(new place());
	tab.push_back(v);
	v.clear();
	//row 28
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 6 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x - 5 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x - 3 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x - 2 * unit, center.y + 6 * unit }));
	v.push_back(new place(23, { center.x - 1 * unit, center.y + 6 * unit }));
	v.push_back(new place(13, { center.x - 0 * unit, center.y + 6 * unit }));
	v.push_back(new place(12, { center.x + 1 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x + 2 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y + 6 * unit }));
	v.push_back(new place(2, { center.x + 6 * unit, center.y + 6 * unit }));
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 29 - thorns
	v.push_back(new place());
	v.push_back(new place());
	v.push_back(new place(0, { center.x - 5.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 4.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 4.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place(0, { center.x + 5.5f * unit, center.y + (6.5f * unit) }));
	v.push_back(new place());
	v.push_back(new place());
	tab.push_back(v);
	v.clear();
	//row 30
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 5 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x - 4 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x - 3 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x - 2 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x - 1 * unit, center.y + 7 * unit }));
	v.push_back(new place(123, { center.x - 0 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x + 1 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x + 2 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x + 4 * unit, center.y + 7 * unit }));
	v.push_back(new place(2, { center.x + 5 * unit, center.y + 7 * unit }));
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();
	//row 31 - thorns
	v.push_back(new place());
	v.push_back(new place());
	v.push_back(new place());
	v.push_back(new place());
	v.push_back(new place(0, { center.x - 3.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x - 2.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x - 1.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x - 0.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 0.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 1.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 2.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place(0, { center.x + 3.5f * unit, center.y + (7.5f * unit) }));
	v.push_back(new place());
	v.push_back(new place());
	v.push_back(new place());
	v.push_back(new place());
	tab.push_back(v);
	v.clear();

	//row 32
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place(2, { center.x - 3 * unit, center.y + 8 * unit }));
	v.push_back(new place(2, { center.x - 2 * unit, center.y + 8 * unit }));
	v.push_back(new place(1, 23, { center.x - 1 * unit, center.y + 8 * unit }));
	v.push_back(new place(3, { center.x - 0 * unit, center.y + 8 * unit }));
	v.push_back(new place(23, { center.x + 1 * unit, center.y + 8 * unit }));
	v.push_back(new place(2, { center.x + 2 * unit, center.y + 8 * unit }));
	v.push_back(new place(2, { center.x + 3 * unit, center.y + 8 * unit }));
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	v.push_back(new place);
	tab.push_back(v);
	v.clear();

}

void board::fill()
{
	//air 11
	tab[0][7]->assign_tile(new tile_air(1));
	tab[0][7]->get_tile()->put(tab[0][7]->get_position());
	//air 12
	tab[0][9]->assign_tile(new tile_air(1));
	tab[0][9]->get_tile()->put(tab[0][9]->get_position());
	//lotus 11
	tab[2][8]->assign_tile(new tile_lotus(1));
	tab[2][8]->get_tile()->put(tab[2][8]->get_position());
	//earth 11
	tab[6][2]->assign_tile(new tile_earth(1));
	tab[6][2]->get_tile()->put(tab[6][2]->get_position());
	//water 11
	tab[6][6]->assign_tile(new tile_water(1));
	tab[6][6]->get_tile()->put(tab[6][6]->get_position());
	//fire 11
	tab[6][10]->assign_tile(new tile_fire(1));
	tab[6][10]->get_tile()->put(tab[6][10]->get_position());
	//earth 12
	tab[6][14]->assign_tile(new tile_earth(1));
	tab[6][14]->get_tile()->put(tab[6][14]->get_position());
	//water 12
	tab[14][3]->assign_tile(new tile_water(1));
	tab[14][3]->get_tile()->put(tab[14][3]->get_position());
	//fire 12
	tab[16][0]->assign_tile(new tile_fire(1));
	tab[16][0]->get_tile()->put(tab[16][0]->get_position());

	//air 21
	tab[32][7]->assign_tile(new tile_air(0));
	tab[32][7]->get_tile()->put(tab[32][7]->get_position());
	//air 22
	tab[32][9]->assign_tile(new tile_air(0));
	tab[32][9]->get_tile()->put(tab[32][9]->get_position());
	//lotus 22
	tab[30][8]->assign_tile(new tile_lotus(0));
	tab[30][8]->get_tile()->put(tab[30][8]->get_position());
	//earth 21
	tab[26][2]->assign_tile(new tile_earth(0));
	tab[26][2]->get_tile()->put(tab[26][2]->get_position());
	//fire 21
	tab[26][6]->assign_tile(new tile_fire(0));
	tab[26][6]->get_tile()->put(tab[26][6]->get_position());
	//water 21
	tab[26][10]->assign_tile(new tile_water(0));
	tab[26][10]->get_tile()->put(tab[26][10]->get_position());
	//earth 22
	tab[26][14]->assign_tile(new tile_earth(0));
	tab[26][14]->get_tile()->put(tab[26][14]->get_position());
	//water 22
	tab[18][13]->assign_tile(new tile_water(0));
	tab[18][13]->get_tile()->put(tab[18][13]->get_position());
	//fire 22
	tab[16][16]->assign_tile(new tile_fire(0));
	tab[16][16]->get_tile()->put(tab[16][16]->get_position());

}

void board::draw_tiles(sf::RenderWindow* window)
{
	for (auto it : tab)
	{
		for (auto it1 : it)
		{
			if (it1->is_drawn())
			{
				window->draw(it1->get_hitbox());
			}
			if (it1->get_tile() != nullptr)
			{
				window->draw(it1->get_tile()->get_circle());
			}
		}
	}
}


