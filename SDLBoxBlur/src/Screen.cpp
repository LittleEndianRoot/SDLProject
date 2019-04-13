/*
 * Screen.cpp
 *
 *  Created on: 12 Apr 2019
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
		cout << "INFO: Failed to initialize video" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion" , SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(m_window == NULL)
	{
		cout << "INFO: Fialed to create window" << endl;
		cout << "ERROR: " << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if(m_renderer == NULL)
	{
		cout << "INFO: Failed to create rendferer" << endl;
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

void Screen::boxBlur()
{
	// Swap the buffers, so pixel is in m_blurBuffer and we are drawing to m_buffer
	Uint32 *temp = m_buffer;


	m_buffer = m_blurBuffer;
	m_blurBuffer = temp;

	for(int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			/*
			 * 0 0 0
			 * 0 1 0
			 * 0 0 0
			 */
			int redTotal = 0;
			int greenTotal = 0;
			int blueTotal = 0;

			for(int row = -1; row <= 1; row++)
			{
				for(int col = -1; col <= 1; col++ )
				{
					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT)
					{
						Uint32 color = m_blurBuffer[(currentY*SCREEN_WIDTH) + currentX];

						Uint8 red = (color & 0xFF000000) >> 24;
						Uint8 green = (color & 0x00FF0000) >> 16;
						Uint8 blue = (color & 0x0000FF00) >> 8;

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

void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		return;
	}

	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	m_buffer[(y * SCREEN_WIDTH) + x] = color;
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

} /* namespace littleendianroot */
