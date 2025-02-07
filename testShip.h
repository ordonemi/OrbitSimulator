/***********************************************************************
 * Header File:
 *    Test Ship : Tests the Ship entity
 * Author:
 *    Austin Jesperson and Emilio Ordonez
 * Summary:
 *    All the unit tests for Ship
 ************************************************************************/

#pragma once

#include <iostream>
#include <cstdlib>
#include "position.h"
#include "ship.h"
#include <cassert>
#include <set>            // for STD::SET

using namespace std;

/**********************************************
 * TEST Ship
 * Contains all the Ship Unit tests
 *********************************************/
class TestShip
{
public:
	void run()
	{
		firstCallbackLoop();
		secondCallbackLoop();
		thirdCallbackLoop();
		fourthCallbackLoop();
		fifthCallbackLoop();
		sixthCallbackLoop();
	}

private:
	Position noAccel;
	Position isAccel = Position(2.0, 0.0);

	// GPS First Callback loop
	void firstCallbackLoop() const
	{
		// setup
		Ship ship;
		Position start;
		start.setPixelsX(-450);
		start.setPixelsY(450);
		// exericse
		
		// verify
		assert(ship.getAngle() == M_PI / 2.0);
		assert(ship.getRadius() == 10.0);
		//assert(ship.getPosition() == start);
		//assert(ship.getVelocity() == Position(0.0, -2000.0));
		assert(ship.getAcceleration() == &noAccel);
	}

	// GPS Second Callback loop
	void secondCallbackLoop() const
	{
		//setup
		Ship ship;
		// exercise
		ship.move(true, false, false);
		// verify
		assert(ship.getAngle() == (M_PI / 2.0 - .1));
	}

	// GPS Third callback Loop
	void thirdCallbackLoop() const
	{
		// setup
		Ship ship;
		// exercise
		ship.move(false, true, false);
		// verify
		assert(ship.getAngle() == (M_PI / 2.0 + .1));
	}

	// GPS Fourth Callback Loop
	void fourthCallbackLoop() const
	{
		// setup
		Ship ship;
		// excersise
		ship.move(false, false, true);
		// verify
		assert(ship.getAcceleration() == &isAccel);
	}

	// GPS Fifth Callback Loop
	void fifthCallbackLoop() const
	{
		// setup
		Ship ship;
		set <Bullet> bullets; 
		// exercise
		//bullets.insert(ship.fire());
		//// verify
		//assert(!bullets.empty());
	}

	// GPS Sixth Callback Loop
	void sixthCallbackLoop() const
	{
		// setup
		Ship ship;
		// exercise
		ship.move(true, true, false);
		// verify
		assert(ship.getAngle() == M_PI / 2.0);
	}

};
