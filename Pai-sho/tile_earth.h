#pragma once
#include "tile.h"
class tile_earth : public tile
{
public:
	tile_earth(bool side);
	~tile_earth();

	int get_type();
	void unmark();
};

