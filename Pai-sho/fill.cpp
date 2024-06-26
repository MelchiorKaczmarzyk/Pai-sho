#include "board.h"
#include "tile.h"
#include "tile_lotus.h"
#include "tile_air.h"
#include "tile_water.h"
#include "tile_earth.h"
#include "tile_fire.h"

void fill(board &board1)
{
	//air 11
	board1.get_tab()[0][7]->assign_tile(new tile_air(1));
	board1.get_tab()[0][7]->get_tile()->put(board1.get_tab()[0][7]->get_position());
	//air 12
	board1.get_tab()[0][9]->assign_tile(new tile_air(1));
	board1.get_tab()[0][9]->get_tile()->put(board1.get_tab()[0][9]->get_position());
	//lotus 11
	board1.get_tab()[2][8]->assign_tile(new tile_lotus(1));
	board1.get_tab()[2][8]->get_tile()->put(board1.get_tab()[2][8]->get_position());
	//earth 11
	board1.get_tab()[6][2]->assign_tile(new tile_earth(1));
	board1.get_tab()[6][2]->get_tile()->put(board1.get_tab()[6][2]->get_position());
	//water 11
	board1.get_tab()[6][6]->assign_tile(new tile_water(1));
	board1.get_tab()[6][6]->get_tile()->put(board1.get_tab()[6][6]->get_position());
	//fire 11
	board1.get_tab()[6][10]->assign_tile(new tile_fire(1));
	board1.get_tab()[6][10]->get_tile()->put(board1.get_tab()[6][10]->get_position());
	//earth 12
	board1.get_tab()[6][14]->assign_tile(new tile_earth(1));
	board1.get_tab()[6][14]->get_tile()->put(board1.get_tab()[6][14]->get_position());
	//water 12
	board1.get_tab()[14][3]->assign_tile(new tile_water(1));
	board1.get_tab()[14][3]->get_tile()->put(board1.get_tab()[14][3]->get_position());
	//fire 12
	board1.get_tab()[16][0]->assign_tile(new tile_fire(1));
	board1.get_tab()[16][0]->get_tile()->put(board1.get_tab()[16][0]->get_position());

	//air 21
	board1.get_tab()[32][7]->assign_tile(new tile_air(0));
	board1.get_tab()[32][7]->get_tile()->put(board1.get_tab()[32][7]->get_position());
	//air 22
	board1.get_tab()[32][9]->assign_tile(new tile_air(0));
	board1.get_tab()[32][9]->get_tile()->put(board1.get_tab()[32][9]->get_position());
	//lotus 22
	board1.get_tab()[30][8]->assign_tile(new tile_lotus(0));
	board1.get_tab()[30][8]->get_tile()->put(board1.get_tab()[30][8]->get_position());
	//earth 21
	board1.get_tab()[26][2]->assign_tile(new tile_earth(0));
	board1.get_tab()[26][2]->get_tile()->put(board1.get_tab()[26][2]->get_position());
	//fire 21
	board1.get_tab()[26][6]->assign_tile(new tile_fire(0));
	board1.get_tab()[26][6]->get_tile()->put(board1.get_tab()[26][6]->get_position());
	//water 21
	board1.get_tab()[26][10]->assign_tile(new tile_water(0));
	board1.get_tab()[26][10]->get_tile()->put(board1.get_tab()[26][10]->get_position());
	//earth 22
	board1.get_tab()[26][14]->assign_tile(new tile_earth(0));
	board1.get_tab()[26][14]->get_tile()->put(board1.get_tab()[26][14]->get_position());
	//water 22
	board1.get_tab()[18][13]->assign_tile(new tile_water(0));
	board1.get_tab()[18][13]->get_tile()->put(board1.get_tab()[18][13]->get_position());
	//fire 22
	board1.get_tab()[16][16]->assign_tile(new tile_fire(0));
	board1.get_tab()[16][16]->get_tile()->put(board1.get_tab()[16][16]->get_position());
}