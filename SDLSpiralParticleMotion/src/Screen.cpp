/*
 * Screen.cpp
 *
 *  Created on: 14 Apr 2019
 *      Author: endian
 */

#include <iostream>
#include "Screen.h"

using namespace std;

namespace littleendianroot
{

Screen::Screen():
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL), m_blurBuffer(NULL)
{

}

bool Screen::init()
{

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "INFO: Failed to initialise video" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_window = SDL_CreateWindow("Particle Spiral Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

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

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

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
	m_blurBuffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	memset(m_blurBuffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	return true;
}

void Screen::clear()
{
	memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	memset(m_blurBuffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}

void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::boxBlur()
{
	Uint32 *temp = m_buffer;

	m_buffer = m_blurBuffer;
	m_blurBuffer = temp;

	for(int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for(int x = 0; x < SCREEN_WIDTH; x++)
		{
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for(int row = -1; row <= 1; row++)
			{
				for(int col = -1; col <= 1; col++)
				{
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT)
					{
						Uint32 colour = m_blurBuffer[(currentY * SCREEN_WIDTH) + currentX];

						Uint8 red = (colour & 0xFF000000) >> 24;
						Uint8 green = (colour & 0x00FF0000) >> 16;
						Uint8 blue = (colour & 0x0000FF00) >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}
				}
			}

			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x, y, red, green, blue);
		}
	}
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		return;
	}

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
	delete [] m_blurBuffer;
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_Quit();
}

} /*namespace littleendianroot*/
