/***********************************************************************
 * Heaader File:
 *    Ship : Entity
 * Author:
 *    Austin Jesperson & Emilio Ordonez
 * Summary:
 *    The ship Dream Chaser controlled by the user.
 ************************************************************************/
#pragma once
#define _USE_MATH_DEFINES
#include "entity.h"
#include "bullet.h"

class Ship : public Entity
{
public:
	Ship();

	void thrust();
	void stopThrust();
	void move(bool isLeft, bool isRight, bool isDown);

	virtual Position* getAcceleration() { return &acceleration; }
	virtual void draw(ogstream& gout) { gout.drawShip(position, angle, isThrusting); }
	virtual void deactivate() {};

	Bullet* fire();

private:
	bool isThrusting = false;
	Position acceleration;
};
