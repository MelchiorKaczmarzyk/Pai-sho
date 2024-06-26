#pragma once
#include "tile.h"

class tile_air : public tile
{
public:
	tile_air(bool side);
	~tile_air();

	int get_type();
	void unmark();
};

