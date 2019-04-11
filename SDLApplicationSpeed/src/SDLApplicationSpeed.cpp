//============================================================================
// Name        : SDLApplicationSpeed.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <math.h>
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
		cout << "Failed to initialize SDL" << endl;
	}

	while(true)
	{

		int elapsedTime = SDL_GetTicks();

		screen.clear();
		swarm.update(elapsedTime);

		unsigned char red = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0004)) * 128);
		unsigned char blue = (unsigned char)((1 + cos(elapsedTime * 0.0003)) * 128);

		const Particle *const pParticle = swarm.getParticle();

		for(int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticle[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);

		}

		screen.update();

		if(screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
