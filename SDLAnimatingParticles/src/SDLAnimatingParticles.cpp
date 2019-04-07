//============================================================================
// Name        : SDLAnimatingParticles.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Screen.h"

using namespace std;
using namespace littleendianroot;

int main()
{
	Screen screen;

	screen.init();

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
