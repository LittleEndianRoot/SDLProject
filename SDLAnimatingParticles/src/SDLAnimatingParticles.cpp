//============================================================================
// Name        : SDLAnimatingParticles.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>

#include <time.h>
#include "Particle.h"

#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace littleendianroot;

int main()
{
	srand(time(NULL));

	Screen screen;
	Swarm swarm;

	if(screen.init() == false)
	{
		cout << "Failed to initialise SDL" << endl;
	}

	while(true)
	{
		// update particles

		// draw particles
		int elapsedTime = SDL_GetTicks();

		screen.clear();
		swarm.update();

		unsigned char red = (unsigned char)((1 + cos(elapsedTime * 0.0003)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.005)) * 128);

		const Particle *const pParticles = swarm.getParticle();
		for(int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

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
