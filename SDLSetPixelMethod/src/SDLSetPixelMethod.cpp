//============================================================================
// Name        : SDLSetPixelMethod.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
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

		// update particles

		// Draw particles
		for(int y=200; y < Screen::SCREEN_HEIGHT-200; y++)
		{
			for(int x = 300; x < Screen::SCREEN_WIDTH-300; x++)
			{
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		// Draw screen
		screen.update();

		// check for message/events
		if(screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
