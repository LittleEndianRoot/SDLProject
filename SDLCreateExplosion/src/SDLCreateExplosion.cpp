//============================================================================
// Name        : SDLCreateExplosion.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include "Screen.h"
#include "Particle.h"
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
		cout << "Failed to initialize SDL" << endl;
	}

	while(true)
	{
		// update particles
		int elapsedTime = SDL_GetTicks();

		swarm.update();
		screen.clear();

		unsigned char red = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0005)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.001)) * 128);

		const Particle *const pParticles = swarm.getParticles();
		// draw particles
		for(int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel( x, y, red, green, blue);
		}

		// update screen
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
