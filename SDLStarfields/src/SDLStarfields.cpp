//============================================================================
// Name        : SDLStarfields.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;
using namespace littleendianroot;

int main()
{

	Screen screen;


	screen.init();

	while(true)
	{
		// update particles

		// draw particles

		// process events/messages
		if(screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
