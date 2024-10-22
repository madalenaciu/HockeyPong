#pragma once
#include "abstractGame.h"
#include "define.h"

class Player : public abstractGame 
	{
	public:

		Player();

		Player(int id, int x, int y);

		void update() override;

		void draw() override;

		void init() override;

		int getX() const;

		int getY() const;

		int getID() const;

		void setX(int x);

		void setY(int y);

		void setID(int id);

		int getPoints() const;

		int getWinner();

		void addPoints();

		void resetPoints();

		int getHeightP() const;

		int getWidthP() const;

		void setHeightP(int h);

		void setWidthP(int w);


	private:

		int id, x, y, widthP, heightP;

		int points = 0;

	};
