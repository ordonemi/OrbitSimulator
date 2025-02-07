/***********************************************************************
 * C++ File:
 *    Bullet
 * Author:
 *    Austin Jesperson and Emilio Ordonez
 * Summary:
 *    A bullet to be fired from our ship
 ************************************************************************/

#pragma once
#include "entity.h"

class Bullet : public Entity
{
public:
	Bullet() : Entity(), time(0.0), lifeSpan(70.0) { radius = 0.5 * 40; }
	Bullet(double t) : Entity(), time(t), lifeSpan(70.0) {} 

	void move();
	void isLiving();
	virtual void draw(ogstream& gout) {gout.drawProjectile(position);}

private:
	double time;
	double lifeSpan;
};