//============================================================================
// Name        : SDLTest.cpp
// Author      : endian
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <SDL.h>

using namespace std;

int main()
{

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL init failed." << endl;
		return 1;
	}

	cout << "SDL init succeeded" << endl;

	SDL_Quit();

	return 0;
}
