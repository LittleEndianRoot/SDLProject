/*
 * Screen.cpp
 *
 *  Created on: 7 Apr 2019
 *      Author: endian
 */

#include "Screen.h"

namespace littleendianroot
{

Screen::Screen()
{
	// TODO Auto-generated constructor stub

}

Screen::~Screen()
{
	// TODO Auto-generated destructor stub
}

bool Screen::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "INFO: Failed to Initialise Video" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(m_window == NULL)
	{
		cout << "INFO: Failed to create window" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if(m_renderer == NULL)
	{
		cout << "INFO: Failed to create renderer" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_Quit();
		return false;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(m_texture == NULL)
	{
		cout << "INFO: Failed to create texture" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_Quit();
		return false;
	}

	m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	return true;
}

bool Screen::processEvents()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			return false;
		}
	}

	return true;
}

void Screen::close()
{
	delete [] m_buffer;
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_Quit();
}


} /* namespace littleendianroot */
