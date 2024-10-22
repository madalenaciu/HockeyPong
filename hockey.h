#pragma once
#include "Player.h"
#include "Ball.h"
#include <vector> 

class Hockey
{
public:
	
	void update();

	void draw();

	void init();

	void game();

	Hockey();

	~Hockey();
private:
	
	std::vector<Player*> listofplayers;

	Ball* ball = nullptr;

	bool menu = false;

	bool ready = false;

	bool end = false;

	double klisi = 0.0;

	const double pi = 3.14;
};