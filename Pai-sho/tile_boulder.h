#pragma once
#include "tile.h"

class tile_boulder : public tile
{
public:
	tile_boulder(bool side);
	~tile_boulder();

	int get_type();
	void unmark();
};

