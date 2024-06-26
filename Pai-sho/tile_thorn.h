#pragma once
#include "tile.h"

class tile_thorn : public tile
{
public:
	tile_thorn(bool side);
	~tile_thorn();

	int get_type();
};

