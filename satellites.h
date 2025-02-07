/***********************************************************************
 * Header File:
 *    Satellites
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    All the satellite classes in our simulation.
 ************************************************************************/
#include "entity.h"
#include "piece.h"
#pragma once

/*********************************************
 * SPUTNIK
 * A Sputnik satellite in our simulation.
 *********************************************/
class Sputnik : public Entity
{
public:
	Sputnik()
	{
		radius = 4.0 * 40.0;
	}

	virtual void draw(ogstream& gout)
	{
		gout.drawSputnik(position, angle);
	}


	virtual vector<Entity*> collide()
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
	};
};


/***************************************
 * GPS
 * A GPS satellite in the simulation.
 ***************************************/
class GPS : public Entity
{
public:
	GPS()
	{
		radius = 25.0 * 40.0;
	}

	virtual vector<Entity*> collide()
	{
		vector<Entity*> pieces;
		GPSLeft* left = new GPSLeft(&position, &velocity);
		GPSRight* right = new GPSRight(&position, &velocity);
		GPSCenter* center = new GPSCenter(&position, &velocity);
		Fragment* one = new Fragment(&position, &velocity);
		Fragment* two = new Fragment(&position, &velocity);
		pieces.push_back(left);
		pieces.push_back(right);
		pieces.push_back(center);
		pieces.push_back(one);
		pieces.push_back(two);
		return pieces;
	};

	virtual void draw(ogstream& gout)
	{
		gout.drawGPS(position, angle);
	}
};


/*************************************************
 * HUBBLE 
 * A Hubble satellite in our simulation.
 ************************************************/
class Hubble : public Entity
{
public:
	Hubble()
	{
		radius = 35.0 * 40.0;
	}

	virtual void draw(ogstream& gout)
	{
		gout.drawHubble(position, angle);
	}

	virtual vector<Entity*> collide()
	{
		vector<Entity*> pieces;
		HubbleLeft* left = new HubbleLeft(&position, &velocity);
		HubbleRight* right = new HubbleRight(&position, &velocity);
		HubbleComp* comp = new HubbleComp(&position, &velocity);
		HubbleTelescope* telescope = new HubbleTelescope(&position, &velocity);
		pieces.push_back(left);
		pieces.push_back(right);
		pieces.push_back(comp);
		pieces.push_back(telescope);
		return pieces;
	};
};


/************************************************
 * DRAGON
 * A Dragon satellite in our simulation.
 ***********************************************/
class Dragon : public Entity
{
public:
	Dragon()
	{
		radius = 18.0 * 40.0;
	}

	virtual vector<Entity*> collide()
	{
		vector<Entity*> pieces;
		DragonLeft* left = new DragonLeft(&position, &velocity);
		DragonRight* right = new DragonRight(&position, &velocity);
		DragonCenter* center = new DragonCenter(&position, &velocity);
		Fragment* one = new Fragment(&position, &velocity);
		Fragment* two = new Fragment(&position, &velocity);

		pieces.push_back(left);
		pieces.push_back(right);
		pieces.push_back(center);
		pieces.push_back(one);
		pieces.push_back(two);
		return pieces;
	};


	virtual void draw(ogstream& gout)
	{
		gout.drawCrewDragon(position, angle);
	}
};


/***********************************************
 * STARLINK 
 * A Starlink satellite in our simulation
 ***********************************************/
class Starlink : public Entity
{
public:
	Starlink()
	{
		radius = 6.0 * 40;
	}

	virtual void draw(ogstream& gout)
	{
		gout.drawStarlink(position, angle);
	}

	virtual vector<Entity*> collide()
	{
		vector<Entity*> pieces;
		StarlinkBody* body = new StarlinkBody(&position, &velocity);
		StarlinkArray* array = new StarlinkArray(&position, &velocity);
		Fragment* one = new Fragment(&position, &velocity);
		Fragment* two = new Fragment(&position, &velocity);
		pieces.push_back(body);
		pieces.push_back(array);
		pieces.push_back(one);
		pieces.push_back(two);
		return pieces;
	};
};