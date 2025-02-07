/***********************************************************************
 * Heaader File:
 *    Entity
 * Author:
 *    Austin Jesperson and Emilio Ordonez
 * Summary:
 *    An Entity in our simulation.
 ************************************************************************/

#pragma once
#include "position.h"
#include "cmath"
#include "uiDraw.h"
#include <vector>

using namespace std;

class Entity
{
public:
	Entity();
	void initialPlacement(double x, double y, double vx, double vy);
	void rotate(double a) {angle += a;}
	void setRadius(double r) { radius = r; }
	void setVelocity(const Position* v) { velocity = *v; }

	double getRotation() const { return rotationSpeed; }
	double getAngle() const { return angle; }
	double getRadius() const { return radius; }

	Position* getPosition() { return &position; }
	Position* getVelocity() { return &velocity; }
	
	bool isActive() const { return active; }
	bool operator == (const Entity& rhs) const { return (position == rhs.position);}

	virtual void draw(ogstream& gout) {};
	virtual vector<Entity*> collide(){vector<Entity*> pieces; return pieces;};
	virtual void deactivate() { active = false; }
	virtual Position* getAcceleration() { return nullptr; }

protected:
	double angle;
	double radius;
	double rotationSpeed;
	Position position;
	Position velocity;
	bool active = true;
};
