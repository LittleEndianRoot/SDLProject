//============================================================================
// Name        : SDLScreenClass.cpp
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

	if(screen.init() == false)
	{
		cout << "Error initialising SDL" << endl;
	}

	while(true)
	{
		// Update particles
		// Draw particles
		// Check for messages/events
		if(screen.processEvents() == false)
		{
			break;
		}

	}

	screen.close();

	return 0;
}
