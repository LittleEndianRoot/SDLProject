//============================================================================
// Name        : SDLSpiralParticleMotion.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
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
		cout << "INFO: Failed to initialise SDL" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		screen.close();
		return 1;
	}

	while(true)
	{
		int elapsedTime = SDL_GetTicks();

		swarm.update(elapsedTime);

		unsigned char red = (unsigned char)((1 + cos(elapsedTime * 0.0004)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0009)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.0006)) * 128);

		Particle const * const pParticle = swarm.getParticle();

		for(int i = 0; i < swarm.NPARTICLES; i++)
		{
			Particle particle = pParticle[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		if(screen.processEvents() == false)
		{
			break;
		}

		screen.boxBlur();
		screen.update();

	}

	screen.close();

	return 0;
}
