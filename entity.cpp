/***********************************************************************
 * C++ File:
 *    Entity
 * Author:
 *    Austin Jesperson and Emilio Ordonez
 * Summary:
 *    An Entity in our simulation.
 ************************************************************************/
#include "entity.h"
#include <random>

/************************************
* ENTITY : CONSTRUCTOR
************************************/
Entity::Entity()
{
	angle = 0.0;
	radius = 0.0;
	rotationSpeed = random(-.03, .03);
	position.setMeters(0.0, 0.0);
	velocity.setMeters(0.0, 0.0);
}

/**************************************
* ENTITY : INITIAL PLACEMENT
***************************************/
void Entity::initialPlacement(double x, double y, double vx, double vy)
{
	position.setMeters(x, y);
	velocity.setMeters(vx, vy);
}

