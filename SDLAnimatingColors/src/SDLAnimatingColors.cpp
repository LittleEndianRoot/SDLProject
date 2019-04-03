//============================================================================
// Name        : SDLAnimatingColors.cpp
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
		cout << "Could not initialise SDL" << endl;
	}

	while(true)
	{

		if(screen.processEvents() == false)
		{
			break;
		}
	}

	screen.close();

	return 0;
}
