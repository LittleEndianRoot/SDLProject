//============================================================================
// Name        : SDLStarfields.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace littleendianroot;

int main()
{
	srand(time(NULL));

	Screen screen;


	if(screen.init() == false)
	{
		cout << "Could not initialise SDL" << endl;
	}

	Swarm swarm;

	while(true)
	{
		// update particles

		// draw particles

		int elapsedTime = SDL_GetTicks();

		unsigned char red = (unsigned char)((1 + sin(elapsedTime * 0.001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.005)) * 128);

		const Particle *const pParticles = swarm.getParticles();
		for(int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x +1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y +1) * Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		// draw screen
		screen.update();

		// process events/messages
		if(screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
