/***********************************************************************
 * Source File:
 *    Simulation : The simulation
 * Author:
 *    Emilio Ordonez & Austin Jesperson
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "simulation.h"
#include "test.h"
using namespace std;

/*************************************
* SIMULATION : CONSTRUCTOR
*************************************/
Simulation::Simulation()
{
    hubble.initialPlacement(0.0, -42164000.0, 3100.0, 0.0);
    starlink.initialPlacement(0.0, -13020000.0, 5800.0, 0.0);
    crewDragon.initialPlacement(0.0, 8000000.0, -7900.0, 0.0);
    sputnik.initialPlacement(36515095.13, 21082000.0, 2050.0, 2684.68);
    firstGPS.initialPlacement(0.0, 26560000.0, -3880.0, 0.0);
    secondGPS.initialPlacement(23001634.72, 13280000.0, -1940.00, 3360.18);
    thirdGPS.initialPlacement(23001634.72, -13280000.0, 1940.00, 3360.18);
    fourthGPS.initialPlacement(0.0, -26560000.0, 3880.0, 0.0);
    fifthGPS.initialPlacement(-23001634.72, -13280000.0, 1940.00, -3360.18);
    sixthGPS.initialPlacement(-23001634.72, 13280000.0, -1940.00, -3360.18);
    angleEarth = 0.0;
    earth.setRadius(1060.0);

    satellites.push_back(&firstGPS);
    satellites.push_back(&secondGPS);
    satellites.push_back(&thirdGPS);
    satellites.push_back(&fourthGPS);
    satellites.push_back(&fifthGPS);
    satellites.push_back(&sixthGPS);
    satellites.push_back(&hubble);
    satellites.push_back(&starlink);
    satellites.push_back(&crewDragon);
    satellites.push_back(&sputnik);
    satellites.push_back(&dreamChaser);
}

/**************************************
 * SIMULATION : CALCULATIONS
 **************************************/
void Simulation::calculations(Position* pos, Position* vel, Position* acc)
{
    int R = 6378000;
    double G = -9.80665;
    double ddx;
    double ddy;

    // Compute Height Above Earth's Surface
    double h = sqrt(pow(pos->getMetersX(), 2.0) + pow(pos->getMetersY(), 2.0)) - R;

    // Compute the magnitude of the acceleration
    double g = G * pow((R / (42164000.0)), 2.0);

    // Compute Direction of Gravity Pull
    double d = atan2(pos->getMetersY(), pos->getMetersX()) - (M_PI / 2);

    if (acc == nullptr)
    {
        // Horizontal component of acceleration
        ddx = -(g * sin(d));

        // Vertical component of acceleration
        ddy = g * cos(d);
    }
    else
    {
        // Horizontal component of acceleration
        ddx = -(g * sin(d) - acc->getMetersX());

        // Vertical component of acceleration
        ddy = g * cos(d) - acc->getMetersY();

        // Bumper car physics
        if (pos->getPixelsX() <= -500 || pos->getPixelsX() >= 500)
        {
            vel->setMetersX(vel->getMetersX() * -1.0);
            ddx = ddx * -1.0;
        }
        if (pos->getPixelsY() <= -500 || pos->getPixelsY() >= 500)
        {
            vel->setMetersY(vel->getMetersY() * -1.0);
            ddy = ddy * -1.0;
        }
    }

    // Horizontal component of velocity
    vel->setMetersX(vel->getMetersX() + ddx * 48.0);

    // Vertical component of velocity
    vel->setMetersY(vel->getMetersY() + ddy * 48.0);

    // New Horizontal and Vertical Distance Formula
    double x = pos->getMetersX() + vel->getMetersX() * 48.0 + ((0.5 * ddx) * pow(48.0, 2));
    double y = pos->getMetersY() + vel->getMetersY() * 48.0 + ((0.5 * ddy) * pow(48.0, 2));

    pos->setMetersX(x);
    pos->setMetersY(y);
}

/*****************************************
 * SIMULATION : RUN 
 ****************************************/
void Simulation::run() 
{
    for (Entity* satellitePtr : satellites) {
        calculations(satellitePtr->getPosition(), satellitePtr->getVelocity(), satellitePtr->getAcceleration());
    }
}

/*****************************************
* SIMULATION : DRAW SATELLITES
******************************************/
void Simulation::drawSatellites()
{
    // Remove inactive satellites from vector first
      satellites.erase(remove_if(satellites.begin(), satellites.end(),
        [](Entity* satellitePtr) { return !satellitePtr->isActive(); }),
        satellites.end());
   
    for (Entity* satellitePtr : satellites) {

        // Rotate satellites
        satellitePtr->rotate(satellitePtr->getRotation());

        // If satellites move past the screen limits, deactive them
        if (satellitePtr->getPosition()->getPixelsX() <= -500 || satellitePtr->getPosition()->getPixelsX() >= 500 || satellitePtr->getPosition()->getPixelsY() <= -500 || satellitePtr->getPosition()->getPixelsY() >= 500) 
        {
            satellitePtr->deactivate();
        }

        // Draw satellites
        satellitePtr->draw(gout);
    }

    // Draw earth
    gout.drawEarth(Position(0.0, 0.0), angleEarth);
}

/********************************************
 * SIMULATION : ADD BULLETS
 *******************************************/
void Simulation::addBullet()
{
    // If there are less than 5 bullets already on screen, add a bullet* to the vector
    if (bullets.size() < 5)
    {
        bullets.push_back(dreamChaser.fire());
    }
}


/*****************************************
* SIMULATION : DRAW BULLETS
******************************************/
void Simulation::drawBullets()
{
    // Erase any bullets that are inactive from vector first
    bullets.erase(remove_if(bullets.begin(), bullets.end(),
        [](Bullet* b) { return !b->isActive(); }),
        bullets.end());

    // Draw remaining active bullets
    for (Bullet* b : bullets) {
        b->draw(gout);
        b->move();
    }
}


/****************************************
 * SIMULATION : CHECK COLLISION
 ****************************************/
void Simulation::checkCollision()
{
    vector<Entity*> pieces;
    // Iterate through each pair of entities in the satellites vector
    for (auto it1 = satellites.begin(); it1 != satellites.end(); ++it1) {
        Entity* entity1 = *it1;
        if (areColliding(entity1, &earth))
        {
            entity1->deactivate();
        }
        // Iterate through all entities after entity1
        for (auto it2 = std::next(it1); it2 != satellites.end(); ++it2) {
            Entity* entity2 = *it2;

            // Check if entity1 and entity2 are colliding
            if (areColliding(entity1, entity2)) {
                vector<Entity*> p = entity1->collide();
                vector<Entity*> p2 = entity2->collide();
                entity1->deactivate();
                entity2->deactivate();

                pieces.insert(pieces.end(), p.begin(), p.end());
                pieces.insert(pieces.end(), p2.begin(), p2.end());
            }
        }

        // Check if entity1 is colliding with bullet
        for (Bullet* b : bullets)
        {
            if (areColliding(entity1, b))
            {
                vector<Entity*> p = entity1->collide();
                entity1->deactivate();
                b->deactivate();

                pieces.insert(pieces.end(), p.begin(), p.end());
            }
        }
    }
    satellites.insert(satellites.end(), pieces.begin(), pieces.end());
}

/****************************************
 * SIMULATION : ARE COLLIDING
 ****************************************/
bool Simulation::areColliding(Entity* entity1, Entity* entity2) {
    // Get positions of entity1 and entity2
    Position* pos1 = entity1->getPosition();
    Position* pos2 = entity2->getPosition();

    // Calculate the distance between the two positions using computeDistance
    double distance = computeDistance(*pos1, *pos2);

    // Check if the distance is less than the sum of their radii (indicating collision)
    double sumOfRadii = pow(entity1->getRadius() * 1.35 + entity2->getRadius() * 1.35, 2);
    return distance < sumOfRadii;
}
