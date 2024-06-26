#pragma once
#include "button_air.h"
#include "button_water.h"
#include "button_earth.h"
#include "button_fire.h"
#include "button_boulder.h"
#include "button_thorn.h"

class button_manager
{
private:
	std::vector<button*> buttons;

public:
	button_manager();
	
	std::vector<button*> get_buttons();
	void fill(bool player1);
	void remove(int type);
};

