/*
 * Screen.cpp
 *
 *  Created on: 2 Apr 2019
 *      Author: endian
 */

#include <iostream>
#include "Screen.h"

using namespace std;

namespace littleendianroot
{

Screen::Screen():
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
{

}

bool Screen::init()
{

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "INFO: Failed to initialise video." << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(m_window == NULL)
	{
		cout << "INFO: Failed to create m_window" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if(m_renderer == NULL)
	{
		cout << "INFO: Could not create m_renderer" << endl;
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
		cout << "INFO: Could not create m_texture" << endl;
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

void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	Uint32 colour = 0;

	colour += red;
	colour <<= 8;
	colour += green;
	colour <<= 8;
	colour += blue;
	colour <<= 8;
	colour += 0xFF;

	m_buffer[(y * SCREEN_WIDTH) + x] = colour;
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
