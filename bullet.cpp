/***********************************************************************
 * C++ File:
 *    Bullet
 * Author:
 *    Austin Jesperson and Emilio Ordonez
 * Summary:
 *    A bullet to be fired from our ship
 ************************************************************************/

#include "bullet.h"

/***********************************
 * BULLET : MOVE 
 ***********************************/
 void Bullet::move()
 {
	 double x = position.getMetersX() + velocity.getMetersX() * 48.0;
	 double y = position.getMetersY() + velocity.getMetersY() * 48.0;

	 position.setMetersX(x);
	 position.setMetersY(y);

	 time += 1.0;
	 isLiving();
 }

/**************************************
 * BULLET : IS LIVING
 **************************************/
 void Bullet::isLiving()
 {
	 if (active = true)
	 {
		 if (lifeSpan <= time)
		 {
			 deactivate();
		 }
	 }
 }


