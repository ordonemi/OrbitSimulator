/***********************************************************************
 * C++ File:
 *    Simulation
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    Handles running the simulation
 ************************************************************************/

#include "piece.h"

/*********************************************
 * PIECE : CONSTRUCTOR 
 *********************************************/
Piece::Piece(Position* old, Position* initV)
{
	double a = atan2(initV->getMetersX(), initV->getMetersY());
	a += random(0.0, M_PI / 2.0);

	double speed = getSpeed(initV);
	speed += random(4000.0, 9000.0);

	Position* start = old;
	start->addPixelsX(splitX(a, 10));
	start->addPixelsY(splitY(a, 10));

	rotationSpeed = random(-.09, .09);

	initialPlacement(start->getMetersX(), start->getMetersY(), splitX(a, speed), splitY(a, speed));
}


/************************************
 * FRAGMENT : MOVE 
 *************************************/
void Fragment::move()
{
	double x = position.getMetersX() + velocity.getMetersX() * 48.0;
	double y = position.getMetersY() + velocity.getMetersY() * 48.0;

	position.setMetersX(x);
	position.setMetersY(y);

	time += 1.0;
	isLiving();
}

/******************************
 * FRAGMENT : IS LIVING
 ******************************/
void Fragment::isLiving()
{
	if (lifeSpan <= time)
	{
		deactivate();
	}
}


/**************************************
 * GPSLEFT : COLLIDE
 *************************************/
vector<Entity*> GPSLeft::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	return pieces;
}

/***************************************
 * GPSRIGHT : COLLIDE
 ************************************/
vector<Entity*> GPSRight::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	return pieces;
}

/******************************************
 * GPSCENTER : COLLIDE
 *****************************************/
vector<Entity*> GPSCenter::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	return pieces;
}

/****************************************
 * HUBBLELEFT : COLLIDE
 ***************************************/
vector<Entity*> HubbleLeft::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	return pieces;
}

/****************************************
 * HUBBLECOMP : COLLIDE 
 ***************************************/
vector<Entity*> HubbleComp::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	return pieces;
}

/*********************************************
 * HUBBLERIGHT : COLLIDE
 *******************************************/
vector<Entity*> HubbleRight::collide() 
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	return pieces;
};

/**********************************************
 * HUBBLETELESCOPE : COLLIDE
 ********************************************/
vector<Entity*> HubbleTelescope::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	return pieces;
}

/*******************************************
 * DRAGONLEFT : COLLIDE
 *******************************************/
vector<Entity*> DragonLeft::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	return pieces;
}

/********************************************
 * DRAGONCENTER : COLLIDE
 *******************************************/
vector<Entity*> DragonCenter::collide()  
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	Fragment* four = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	pieces.push_back(four);
	return pieces;
}

/*******************************************
 * DRAGONRIGHT : COLLIDE
 ******************************************/
vector<Entity*> DragonRight::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	return pieces;
}

/*******************************************
 * STARLINKBODY : COLLIDE
 ******************************************/
vector<Entity*> StarlinkBody::collide() 
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	return pieces;
}

/******************************************
 * STARLINKARRAY : COLLIDE
 *****************************************/
vector<Entity*> StarlinkArray::collide()
{
	vector<Entity*> pieces;
	Fragment* one = new Fragment(&position, &velocity);
	Fragment* two = new Fragment(&position, &velocity);
	Fragment* three = new Fragment(&position, &velocity);
	pieces.push_back(one);
	pieces.push_back(two);
	pieces.push_back(three);
	return pieces;
}
