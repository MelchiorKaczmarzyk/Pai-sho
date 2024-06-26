#pragma once
#include "tile.h"
class tile_fire : public tile
{
public:
	tile_fire(bool side);
	~tile_fire();

	int get_type();
	void unmark();
};

