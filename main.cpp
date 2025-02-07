/***********************************************************************
 * Source File:
 *    Main 
 * Author:
 *    Emilio Ordonez & Austin Jesperson
 * Summary:
 *    Starts main() and callback
 ************************************************************************/
#include "simulation.h"

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Simulation* pSim = (Simulation*)p;

    ////
    //// accept input
    ////
    pSim->moveShip();
    if (pUI->isSpace()) { pSim->addBullet(); }

    //
    // perform all the game logic (in this case logic to rotate the satellite
    //
    pSim->run();

    //
    // Check for collisions
    //
    pSim->checkCollision();

    //
    //rotate the earth
    //
    pSim->rotateEarth();

    //
    // draw everything
    //
    Position pt;
    pSim->drawSatellites(); 
    pSim->drawBullets();
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);
    Interface ui(0, NULL,
        "Orbit Simulator",   /* name on the window */
        ptUpperRight);

    // Initialize the demo
    Simulation sim;

    // set everything into action
    ui.run(callBack, &sim);
    //testRunner();

    return 0;
}
