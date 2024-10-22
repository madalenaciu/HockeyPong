#pragma once
#include "define.h"
#include <graphics.h>
#include "hockey.h"
#include "Info.h" 

class Menu 
{
public:

	Menu();

	~Menu();

	void update();

	void draw();

	void init();

	bool menu = true;

	void getState();

	Hockey* hockey = nullptr;

	Info* info = nullptr;
};
