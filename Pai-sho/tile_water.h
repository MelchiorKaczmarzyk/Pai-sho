#pragma once
#include "tile.h"
class tile_water : public tile
{
	bool harmonised1 = 0;
public:
	tile_water(bool side);
	~tile_water();

	int get_type();
	void unmark();
	void harmonise();
	void deharmonise();
};

