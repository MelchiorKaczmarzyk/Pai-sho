#pragma once
#include "tile.h"

class tile_lotus : public tile
{
public:
	tile_lotus(bool side);
	~tile_lotus();

	int get_type();
	void unmark();
};

