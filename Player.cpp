#include "player.h"
#include "graphics.h"
#include "define.h"

Player::Player(){
	id = 0;
	x = 0;
	y = 0;
    widthP = 0;
    heightP = 0;
}
Player::Player(int id, int x, int y) {
	setID(id);
	setX(x);
	setY(y);
	setWidthP(40);
	setHeightP(100);
}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_E) && id == 1) 
	{
		this->y -= 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S) && id == 1) 
	{
		this->y += 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_UP) && id == 2) 
	{
		this->y -= 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_DOWN) && id == 2) 
	{
		this->y += 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_A) && id == 1)
	{
		this->x -= 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D) && id == 1)
	{
		this->x += 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_LEFT) && id == 2)
	{
		this->x -= 12;
	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT) && id == 2)
	{
		this->x += 12;
	}
	
}

void Player::draw()
{
	graphics::Brush br;

	br.texture = ASSET_PATH + std::string("pioni.png");

	graphics::drawRect(this->x, this->y, widthP, heightP, br);

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	
	if (getID() == 1) {
		graphics::drawText(280, 40, 20, "POINTS OF PLAYER " + std::to_string(getID()) + " :   " + std::to_string(getPoints()), br);
	}
	else {
		graphics::drawText(525, 40, 20, "POINTS OF PLAYER " + std::to_string(getID()) + " :   " + std::to_string(getPoints()), br);
	}
	graphics::setFont(std::string(ASSET_PATH) + "caesar.ttf");

}

void Player::init()
{
	
}

int Player::getX() const
{
	return this->x;
}

int Player::getY() const
{
	return this->y;
}

int Player::getID() const
{
	return  id;
}

void Player::setX(int x)
{
	this->x = x;
}

void Player::setY(int y)
{
	this->y = y;
}

void Player::setID(int id)
{
	this->id = id;
}


int Player::getPoints() const
{
	return points;
}


void Player::addPoints()
{
	points++;
}

void Player::resetPoints()
{
	points = 0;
}

int Player::getWidthP() const 
{

	return	widthP;

}

int Player::getHeightP() const
{
	return heightP;
}

void Player::setWidthP(int w)
{ 
	this->widthP = w;
}
void Player::setHeightP(int h ) 
{
	this->heightP = h;
}

int Player::getWinner() {

	if (points == 10) { return this->id; }
}
