/***********************************************************************
 * C++ File:
 *    Simulation
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    Handles running the simulation
 ************************************************************************/

#pragma once
#define _USE_MATH_DEFINES 
#include "entity.h"
#include <random>
#include <math.h> 

using namespace std;

class Piece : public Entity
{
public:
	Piece() {}
	Piece(Position* old, Position* initV);
	
	double getSpeed(Position* initV){return sqrt(pow(initV->getMetersX(),2) + pow(initV->getMetersY(),2));}
	double splitX(double a, double amount){return amount * sin(a);}
	double splitY(double a, double amount){return amount * cos(a);}
};

class Fragment : public Piece
{
public:
	Fragment() : Piece(), time(0.0), lifeSpan(70.0) {}
	Fragment(Position* old, Position* initV) : Piece(old, initV), time(0.0), lifeSpan(random(50.0, 100.0)) { radius = 2.0 * 40.0; }

	void move();
	void isLiving();
	
	virtual void draw(ogstream& gout){gout.drawFragment(position, angle);}

private:
	double time;
	double lifeSpan;
};

class GPSLeft : public Piece
{
public:
	GPSLeft(Position* old, Position* initV) : Piece(old, initV) { radius = 8.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawGPSLeft(position, angle, Position());}
	virtual vector<Entity*> collide();
};

class GPSRight : public Piece
{
public:
	GPSRight(Position* old, Position* initV) : Piece(old, initV) { radius = 8.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawGPSRight(position, angle, Position());}
	virtual vector<Entity*> collide();
};

class GPSCenter : public Piece
{
public:
	GPSCenter(Position* old, Position* initV) : Piece(old, initV) { radius = 7.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawGPSCenter(position, angle);}
	virtual vector<Entity*> collide();
};

class HubbleLeft : public Piece
{
public:
	HubbleLeft(Position* old, Position* initV) : Piece(old, initV) { radius = 8.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawHubbleLeft(position, angle, Position());}
	virtual vector<Entity*> collide();
};


class HubbleComp : public Piece
{
public:
	HubbleComp(Position* old, Position* initV) : Piece(old, initV) { radius = 7.0 * 40; }

	virtual void draw(ogstream& gout){gout.drawHubbleComputer(position, angle, Position());}
	virtual vector<Entity*> collide();
};

class HubbleRight : public Piece
{
public:
	HubbleRight(Position* old, Position* initV) : Piece(old, initV) { radius = 8.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawHubbleRight(position, angle, Position()); }
	virtual vector<Entity*> collide();
};

class HubbleTelescope : public Piece
{
public:
	HubbleTelescope(Position* old, Position* initV) : Piece(old, initV) { radius = 10.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawHubbleTelescope(position, angle, Position());}
	virtual vector<Entity*> collide();
	
};

class DragonLeft : public Piece
{
public:
	DragonLeft(Position* old, Position* initV) : Piece(old, initV) { radius = 6.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawCrewDragonLeft(position, angle, position);}
	virtual vector<Entity*> collide();
};

class DragonCenter : public Piece
{
public:
	DragonCenter(Position* old, Position* initV) : Piece(old, initV) { radius = 6.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawCrewDragonCenter(position, angle);}
	virtual vector<Entity*> collide();
};

class DragonRight : public Piece
{
public:
	DragonRight(Position* old, Position* initV) : Piece(old, initV) { radius = 6.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawCrewDragonRight(position, angle, position);}
	virtual vector<Entity*> collide();
};

class StarlinkBody : public Piece
{
public:
	StarlinkBody(Position* old, Position* initV) : Piece(old, initV) { radius = 2.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawStarlinkBody(position, angle, position);}
	virtual vector<Entity*> collide();
};

class StarlinkArray : public Piece
{
public:
	StarlinkArray(Position* old, Position* initV) : Piece(old, initV) { radius = 4.0 * 40.0; }

	virtual void draw(ogstream& gout){gout.drawStarlinkArray(position, angle, position);}
	virtual vector<Entity*> collide();
};

