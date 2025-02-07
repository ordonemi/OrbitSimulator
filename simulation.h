/***********************************************************************
 * C++ File:
 *    Simulation
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    Handles running the simulation
 ************************************************************************/
#pragma once
#include "position.h"
#include "uiDraw.h"
#include "satellites.h"
#include "ship.h"
#include "bullet.h"
#include "piece.h"
#include "uiInteract.h"
#include <vector>

class Simulation
{
public:
    Simulation();

    void moveShip() { dreamChaser.move(pUI.isLeft(), pUI.isRight(), pUI.isDown()); }
    void rotateEarth() { angleEarth += (-(2.0 * M_PI / 30.0) * (1440.0 / 86400.0)); }
    void drawSatellites();
    void drawBullets();
    void checkCollision();
    void run();
    void addBullet();
    void calculations(Position* pos, Position* vel, Position* acc = nullptr);
    bool areColliding(Entity* entity1, Entity* entity2);

private:
    Interface pUI;
    ogstream gout;
    Hubble hubble;
    Sputnik sputnik;
    Starlink starlink;
    Dragon crewDragon;
    Ship dreamChaser;
    GPS firstGPS;
    GPS secondGPS;
    GPS thirdGPS;
    GPS fourthGPS;
    GPS fifthGPS;
    GPS sixthGPS;
    vector<Entity*> satellites;
    vector<Bullet*> bullets;
    double angleEarth;
    Entity earth;
};