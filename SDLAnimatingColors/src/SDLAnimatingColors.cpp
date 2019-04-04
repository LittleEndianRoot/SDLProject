//============================================================================
// Name        : SDLAnimatingColors.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace littleendianroot;

int main()
{

	Screen screen;

	if(screen.init() == false)
	{
		cout << "Could not initialise SDL" << endl;
	}

	while(true)
	{
		// Update particles

		// draw particles
		int elapsedTime = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + cos(elapsedTime * 0.0003)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsedTime * 0.0001)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsedTime * 0.005)) * 128);

		for(int y = 250; y < Screen::SCREEN_HEIGHT-250; y++)
		{
			for(int x = 350; x < Screen::SCREEN_WIDTH-350; x++)
			{
				screen.setPixel(x, y, red, green, blue);
			}
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
