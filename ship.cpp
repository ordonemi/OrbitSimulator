/***********************************************************************
 * C++ File:
 *    Ship
 * Author:
 *    Austin Jesperson & Emilio Ordonez
 * Summary:
 *    An Ship in our simulation
 ************************************************************************/
#include "ship.h"

/******************************************
 * SHIP : CONSTRUCTOR
 *****************************************/
Ship::Ship()
{
	angle = M_PI / 2.0;
	radius = 10 * 40;
	position.setPixelsX(-450.0);
	position.setPixelsY(450.0);
	velocity.setMeters(0.0, -2000.0);
	acceleration.setMeters(0.0, 0.0);
	rotationSpeed = 0.0;
}

/*****************************************
 * SHIP : THURST
 ****************************************/
void Ship::thrust()
{
	acceleration.setMetersX(2.0 * cos(angle - (M_PI / 2.0)));
	acceleration.setMetersY(2.0 * sin(angle - (M_PI / 2.0)));
}


/******************************************
 * SHIP : STOP THRUST 
 *****************************************/
void Ship::stopThrust()
{
	acceleration.setMetersX(0.0);
	acceleration.setMetersY(0.0);
}


/************************************************
 * SHIP : MOVE
 ************************************************/
void Ship::move(bool isLeft, bool isRight, bool isDown)
{
	if (isLeft && !isRight)
	{
		rotate(-.1);
	}

	if (!isLeft && isRight)
	{
		rotate(.1);
	}

	if (isDown)
	{
		isThrusting = true;
		thrust();
	}

	if (!isDown)
	{
		isThrusting = false;
		stopThrust();
	}
}


/***************************************
 * SHIP : FIRE
 **************************************/
Bullet* Ship::fire()
{
	Bullet* bullet = new Bullet();

	Position start;
	start.setPixelsX(position.getPixelsX() + 19.0 * sin(angle));
	start.setPixelsY(position.getPixelsY() + 19.0 * cos(angle));
	double vx = velocity.getMetersX() + 9000 * sin(angle);
	double vy = velocity.getMetersY() + 9000 * cos(angle);

	bullet->initialPlacement(start.getMetersX(), start.getMetersY(), vx, vy);
	return bullet;
}