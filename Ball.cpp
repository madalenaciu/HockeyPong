#include "Ball.h"
#include <graphics.h>
#include <string>



void Ball::update()
{

	this->x += Speed;

	this->y += dir; 

}

void Ball::draw()
{
	graphics::Brush b;

	b.texture = std::string(ASSET_PATH) + "ice.png";

	graphics::drawDisk(this->x, this->y, 10, b);
}

void Ball::init()
{

}

Ball::Ball(int x, int y, int Speed)
{
	this->x = x;

	this->y = y;

	this->Speed = Speed;

}


int Ball::getX() const
{
	return x;
}

int Ball::getY() const
{
	return y;
}



float Ball::getDirection() const
{
	return dir;
}


int Ball::getSpeed() const
{
	return Speed;
}

void Ball::setSpeed(int Speed)
{
	this->Speed = Speed;
}

void Ball::setDirection(float d)
{
	dir = d;
}
void Ball::setX(double x) {

	this->x = x;
}
void Ball::setY(double y)
{
	this->y = y;
}