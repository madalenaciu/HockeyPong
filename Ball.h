#pragma once
#include "Player.h"
#include "abstractGame.h"

class Ball : public abstractGame{

public:

	Ball(int x, int y, int Speed);

	void update() override;

	void draw() override;

	void init() override;

	float getDirection() const;

	int getX() const;

	int getY() const;

	int getSpeed() const;

	void setX(double x);

	void setY(double y);

	void setSpeed(int speed);

	void setDirection(float dir);

private:

	double x, y;

	double dir = 0.0;

	int Speed;
};