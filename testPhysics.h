/***********************************************************************
 * Header File:
 *    Test Physics : Tests the Physics Engine
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    All the unit tests for Physics
 ************************************************************************/

#pragma once

#include <iostream>
#include <cstdlib>
#include "position.h"
#include <cassert>
#include "simulation.h"

using namespace std;

/**********************************************
 * TEST Physics
 * Contains all the Physics Unit tests
 *********************************************/
class TestPhysics
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
	// GPS First Callback loop
	void firstCallbackLoop() const
	{
		// setup
		Position pos = Position(0.0, 42164000.0);
		Position vel = Position(3100.0, 0.0);
		Simulation engine;
		// exericse
		engine.calculations(&pos, &vel);
		// verify
		assert(abs(pos.getMetersX() - (148800.0)) < 0.1);
		assert(abs(pos.getMetersY() - 42163224.5) < 0.1);
	}

	// GPS Second Callback loop
	void secondCallbackLoop() const
	{
		//setup
		Position pos = Position(-148800.0, 42163224.5);
		Position vel = Position(-3100.0, -10.7708);
		Simulation engine;
		// exercise
		engine.calculations(&pos, &vel);
		// verify
		assert(abs(pos.getMetersX() - (-297597.2)) < 0.1);
		assert(abs(pos.getMetersY() - 42161932.0) < 0.1);
	}

	// GPS Third callback Loop
	void thirdCallbackLoop() const
	{
		// setup
		Position pos = Position(-297597, 42161932.0);
		Position vel = Position(-3099.96, -21.5415);
		Simulation engine;
		// exercise
		engine.calculations(&pos, &vel);
		// verify
		assert(abs(pos.getMetersX() - (-446389.6)) < 0.1);
		assert(abs(pos.getMetersY() - 42160122.5) < 0.1);
	}

	// GPS Fourth Callback Loop
	void fourthCallbackLoop() const 
	{
		// setup
		Position pos = Position(-446390, 42160122.5);
		Position vel = Position(-3099.89, -32.312);
		Simulation engine;
		// excersise
		engine.calculations(&pos, &vel);
		// verify
		assert(abs(pos.getMetersX() - (-595176.5)) < 0.1);
		assert(abs(pos.getMetersY() - 42157796.0) < 0.1);
	}

	// GPS Fifth Callback Loop
	void fifthCallbackLoop() const
	{
		// setup
		Position pos = Position(-595176, 42157796.0);
		Position vel = Position(-3099.77, -43.0822);
		Position acceleration = Position(0, 0);
		Simulation engine;
		// exercise
		engine.calculations(&pos, &vel);
		// verify
		assert(abs(pos.getMetersX() - (-743954.0)) < 0.1);
		assert(abs(pos.getMetersY() - 42154952.6) < 0.1);
	}

	// GPS Sixth Callback Loop
	void sixthCallbackLoop() const
	{
		// setup
		Position pos = Position(-743954, 42155000);
		Position vel = Position(-3099.62, -53.8519);
		Simulation engine;
		// exercise
		engine.calculations(&pos, &vel);
		// verify
		assert(abs(pos.getMetersX() - (-892722.0)) < 0.1);
		assert(abs(pos.getMetersY() - 42151639.7) < 0.1);
	}
};
